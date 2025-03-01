#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>

//#pragma comment(lib, "ws2_32.lib")

using namespace std;
/*
//initilize the winsock library
//create the socket
//get the ip and port and run it on local host
//bind the ip/port with the socket
//listen to the socket
//accept
//receive and sned
//close the socket
*/
bool Initialize(){
    WSADATA data;
    return WSAStartup(MAKEWORD(2, 2), & data) == 0;
}

void InteractWithClient(SOCKET clientSocket, vector<SOCKET>& clients){
    //send and receice client
    cout<<"client connected"<<endl;
    char buffer[4096];

    while(1){//run the server infinitely until explicitly stopped
        int bytesrecvd=recv(clientSocket, buffer, sizeof(buffer), 0);

        if(bytesrecvd<=0){//no response or client disconnected
            cout<<"client disconnected"<<endl;
            break;
        }
        string message(buffer,bytesrecvd);
        cout<<"Message from client: "<<message<<endl;

        //forward the message to all the clients
        for(SOCKET& client: clients){
            if(client!=clientSocket){
                send(client, message.c_str(), message.size(), 0);
            }
        }
    }

    auto it=find(clients.begin(), clients.end(), clientSocket);
    if(it!=clients.end()){
        clients.erase(it);
    }

    closesocket(clientSocket);

}
int main(){
    if(!Initialize()){
        cout<<"winsock intialisation failed"<<endl;
        exit(1);
    }

    SOCKET listenScoket=socket(AF_INET,SOCK_STREAM,0); 

    if(listenScoket==INVALID_SOCKET){
        cout<<"socket creation failed"<<endl;
        exit(1);
    }

    //creatting address structure
    sockaddr_in serveraddr;
    serveraddr.sin_family=AF_INET;
    int port = 12345;
    serveraddr.sin_port=htons(port);//host to network short
    
    //convert the ip address to binary(0.0.0.0) //local address
    if(InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr)<=0){
        cout<<"ip address conversion failed"<<endl;
        closesocket(listenScoket);
        WSACleanup();
        exit(1);
    }

    //bind the ip and port with the socket
    if(bind(listenScoket, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr))){
      cout<<"binding failed"<<endl;
      closesocket(listenScoket);
        WSACleanup();
        exit(1);
    } 


    if(listen(listenScoket, SOMAXCONN)){
        //listen to the socket and maximum 5 clients can connect
    //SOMAXCONN is the maximum number of clients signed integer value
        cout<<"listening failed"<<endl;
        closesocket(listenScoket);
        WSACleanup();
        exit(1);
    }

    cout<<"server is listening on port"<< port <<endl;

    vector<SOCKET> clients;

    while(1){
        //accept the client
    SOCKET clientSocket= accept(listenScoket, nullptr, nullptr);
    //when we accept the client we get the client socket of SOCKET type
    if(clientSocket==INVALID_SOCKET){
        cout<<"client connection failed"<<endl;
        closesocket(listenScoket);
        WSACleanup();
        exit(1);
    }

    clients.push_back(clientSocket);

    //with one accept we can only accept one client, so we create thread to accept multiple clients and run the server
     thread t1(InteractWithClient, clientSocket, ref(clients));//send clients vector as reference
     //write InteractWithClient function to interact with multiple client
     t1.detach();//detach the thread
    }

    // char buffer[4096];//code is for single client and one message
    // //client receives string "hello", that is stored in buffer and the size of buffer is 5 stored in bytesrecvd
    // int bytesrecvd=recv(clientSocket, buffer, 4096, 0);

    // string message(buffer,bytesrecvd);
    // cout<<"Message from client: "<<message<<endl;
    // closesocket(clientSocket);
    // closesocket(listenScoket);
    WSACleanup();

    return 0;
}