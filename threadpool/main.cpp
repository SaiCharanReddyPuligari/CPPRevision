#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

void Func(){
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Thread ID: "<<this_thread::get_id()<<endl;
}

class Threadpool{
    private:
    int m_threads;
    vector<thread> threads;
    queue<std::function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;

    public:
    explicit Threadpool(int numThreads):m_threads(numThreads), stop(false){
        for(int i=0;i<m_threads;i++){
            threads.emplace_back([this]{
                std::function<void()> task;
                while(1){
                    {
                        unique_lock<mutex> lock(mtx); //locking the thread
                        cv.wait(lock, [this]{ //rechecking with condition variable
                            return !stop || !tasks.empty();
                        });
                        if(stop){
                            return;
                        }
                        task = move(tasks.front());
                        tasks.pop();

                        lock.unlock();
                        task();
                    }
                }
            });
        }
    }
};

int main(){
     while(1){
        Threadpool pool(8);
        pool.ExecuteTask(Func);
     }
    cout<<"ThreadPool implementation"<<endl;
    return 0;
}