#include<iostream>
#include<thread>
#include<bits/stdc++.h>
using namespace std;
// void test(int x, int y){
//     cout<<"This is child thread"<<endl;
//     cout<<"the value is "<<x<<" "<< y<<endl;
// }
mutex mt; //we use the mutex mt to lock shared resources
static int shared_value=0;
//this shared value will result in data race condition in multithreaded environment
// and we use MUTEX(Mutual Exclusion) to protect shared values (a thread upon access, locks the shared value and is only available when the thread releases)

void shared_value_increment(){
    mt.lock();  //lock the sa
      shared_value+=1;
    mt.unlock();
}

int main(){
    
    vector<thread> threads;
    for(int i=0;i<100;i++){
       threads.push_back(thread(shared_value_increment));
    }
    
    for(int i=0;i<100;i++){
        threads[i].join();
    }

    cout<<"this is shared value "<<shared_value<<endl;
    return 0; 
}