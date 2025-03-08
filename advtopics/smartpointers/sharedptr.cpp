#include <iostream>
using namespace std;

template <typename T>
class sharedptr{
    T *res;
    //int count or static int count; //not possible as it creates new counter value on stack for every obj rather than holding the value
    int* count; //this helps us maintaing only one instance of count

    void incrementCounter(){
        if(counter){
            (*counter)++;
        }
        
    }
    void decrementCounter(){
        if(counter){
            (*counter)--;
            if((*counter)==0){ //if the counter is 0 we have to delete
                if(res){
                    delete res; 
                    delete counter;
                    res=nullptr;
                    counter=nullptr;
                }
            }
        } 
    }
    public:
    sharedptr(T* ptr=nullptr):res(ptr), count(new int(1)){
        //default and param const in one
        cout<<"ctor"<<endl;
    }

    sharedptr<T>(const sharedptr<T>& prt){
        res = ptr.res;
        count = ptr.count;
        incrementCounter();
    }

    sharedptr<T> ( sharedptr<T>&& prt){
        res = ptr.res;
        count = ptr.count;
        ptr.res= nullptr;
        ptr.count= nullptr;
    }

    sharedptr<T>& operator = (const sharedptr<T>& ptr){
            if(this!=&ptr){
                decrementCounter();
                res = ptr.res;
                count = ptr.count;
                incrementCounter();
            }
            return *this;
    }

    sharedptr<T>& operator = (sharedptr<T>& ptr){
        if(this!=&ptr){
            decrementCounter();
            res = ptr.res;
            count = ptr.count;
            ptr.res=nullptr;
            prt.count = nullptr;
        }
        return *this;
    }

    void reset(T* ptr){
        decrementCounter();
        res=prt;
        count = new int(1);
    }

    int get_count(){
        if(count){
            return (*counter);
        }
        return -1;
    }

    T* operator->(){
        return res;
    }

    T& operator*(){
        return (*res);
    }

    T* get(){
        return res;
    }

    ~sharedptr(){
        decrementCounter();//we decrement rather than delete, as there can be multple shared pointer
        //if shared pointers count =0, the deleteCounter takes care of that

    }

};

int main(){
     sharedptr<int> ptr1;//default cons
     sharedptr<int> ptr2(new int(10)); //param const
     sharedptr<int> ptr3(ptr2); //copy const
     ptr3=ptr2; //assignment 
     sharedptr<int> ptr4(move(ptr1)); //move copy ctor
     ptr2 = move(ptr3);

    //  ptr1.reset();
    //  prt1.reset(new int(5));

    //  cout<<*ptr1;
    //  ptr1->func();
    ptr1.get_count();
}