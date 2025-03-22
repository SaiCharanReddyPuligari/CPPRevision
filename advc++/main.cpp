#include <iostream>
#include <thread>
#include <atomic>
#include <future>
//int count=0;
#include <mutex>
std::mutex mt;
std::atomic<int> count;

void run(){
    //mt.lock();
    //std::unique_lock<std::mutex> lock(mt);
    for(int i=0;i<1000000;i++){
        count++;
    }
    //mt.unlock();
}

//promise and future use to connect threads which depends on the result on one another

void step5(std::promise<int> &&p1, long long start, long long end) {
    long long oddSum=0;
    for(long long i=0;i<=end;i++){
        if(i&1){
            oddSum+=i;
        }
    }
    p1.set_value(oddSum);
}

void task(std::promise<int> &p){
    try{
        throw std::runtime_error("Task Failed");
    }catch(std::exception& e){
        p.set_exception(std::current_exception());
    }
}

int main(){
    // long long start=0, end=190000;
    // std::promise<int> p1;
    // //std::promise<int> p1;
    // std::future<int> f1 = p1.get_future();
    // std::thread t1(step5, std::move(p1), start, end);
    // std::cout<<f1.get()<<std::endl;

    // t1.join();

    std::promise<int> p;
    std::future<int> f= p.get_future();
    
    std::thread t1(task, std::ref(p));
    t1.join();

    try{
        int res=f.get();

    }catch(const std::exception& e){
        std::cout<<"Eception: "<<e.what()<<std::endl;
    }

    return 0;

    
}