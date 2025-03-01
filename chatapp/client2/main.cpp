#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <string>
#include <sstream>
using namespace std;

/*
initialize winsock library
create the socket
connect to the server
send/receive
close the socket
*/
bool Initialize(){
    WSADATA data;
    return WSAStartup(MAKEWORD(2, 2), & data) == 0;
}

void sendmessage(SOCKET s){
    cout<<"Enter your chat name :" <<endl;
    string name;
    getline(cin, name);
    string message;
    while(1){ //continous
        
        // cout<<"Enter the message to send: ";
        getline(cin, message);
        string msg=name+": "+message;
        int bytes_sent=send(s, msg.c_str(), msg.size(), 0);
        if(bytes_sent<=SOCKET_ERROR){
            cout<<"sending failed"<<endl;
            break;
        }

        if(message=="exit"){
            cout<<"exiting chat"<<endl;
            break;
        }
    }
    closesocket(s);
    WSACleanup();
}
void receivemessage(SOCKET s){
    char buffer[4096];
    int bytes_received;
    //string msg="";
    while(1){
        int bytes_received=recv(s, buffer, sizeof(buffer), 0);
        if(bytes_received<=0){
            cout<<"server disconnected"<<endl;
            break;
        }
        else{
            string message(buffer, bytes_received);
            // stringstream ss;
            // getline(ss, message, ':');

            cout<<"Message from server: "<<message<<endl;
            if(message=="exit"){
                cout<<"exiting chat"<<endl;
                break;
            }
        }
    }

    closesocket(s);
    WSACleanup();
}
int main(){
    if(!Initialize()){
        cout<<"winsock intialisation failed"<<endl;
        exit(1);
    }

    SOCKET s=socket(AF_INET,SOCK_STREAM,0);
    if(s==INVALID_SOCKET){
        cout<<"socket creation failed"<<endl;
        exit(1);
    }
    int port = 12345;
    string serveraddress="127.0.0.1";
    sockaddr_in serveraddr;
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(12345);
    inet_pton(AF_INET, serveraddress.c_str(), &serveraddr.sin_addr);

    if(connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr))==SOCKET_ERROR){
        cout<<"connection failed"<<endl;
        closesocket(s);//close and clean up
        WSACleanup();
        exit(1);
    }

    cout<<"connected to the server"<<endl;
    //we create two threads to send and receive messages parallely
    thread senderThread(sendmessage, s);
    thread receiverThread(receivemessage, s);
    //send and recv
    //the sending, receiving and closing of the socket is done in the threads
    senderThread.join();
    receiverThread.join();
    //join waits until main execution is done whereas detach runs independently
    // string message="Hello from client";
    // int bytes_sent=send(s, message.c_str(), message.size(), 0); //since c takes char array we covert it to string
    // if(bytes_sent==SOCKET_ERROR){
    //     cout<<"sending failed"<<endl;
    //     closesocket(s);
    //     WSACleanup();
    //     exit(1);
    // }


    // closesocket(s);
    // WSACleanup();
    return 0;
}   