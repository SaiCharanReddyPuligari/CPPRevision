#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
mutex m1;
#include <atomic>

atomic<int> counter;


using namespace std;

int main(){

    //lock_guard<mutex> lock(m1);

    // (//ftream object to write
    // ofstream fout;
    // fout.open("zoom.txt"); //open file
    // //write
    // fout<<"Hello India";
    // fout.close();//closing helps in releasing the allocated resources)

//    ( ///fstream object to read
//     ifstream fin;
//     //open file
//     fin.open("zoom.txt");
//     //read
//     char c;
//     fin>>c;//this does not consider space
//     //we use 
//     c=fin.get(); //to read space
//     while(!fin.eof()){
//        cout<<c;
//        //fin>>c;
//        c=fin.get();
//     }
//     fin.close();)

//string vector data in file
// (vector<int> arr(5);
// for(int i=0;i<5;i++){
//     cin>>arr[i];
// }

// ofstream fout;
// fout.open("zoom.txt");

// for(int i=0;i<5;i++){
//     fout<<arr[i]<<" ";
// }

// fout.close();)

ofstream fout;
fout.open("zoom.txt");

fout<<"Hello Sai\n";
fout<<"Hello Babu\n";

fout.close();

ifstream fin;
fin.open("zoom.txt");

string line;
while(getline(fin, line)){
    cout<<line<<endl;
}

fin.close();

}