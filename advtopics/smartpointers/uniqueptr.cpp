#include <iostream>
using namespace std;

template <typename T> //T can be any type of object, datatypes
class uniqueptr{

    private:
    T* res; //same size as raw pointers and no increase in size

    public:
        uniqueptr(T* a=nullptr): res(a){
            cout<<"ctor"<<endl;
        }

        uniqueptr(const uniqueptr<T>& ptr) = delete;
        uniqueptr& operator = (const uniqueptr<T>& ptr) = delete;

        uniqueptr(uniqueptr<T>&& ptr){
            res = ptr.res;
            ptr.res = nullptr;
        }

        uniqueptr& operator = (uniqueptr<T>&& ptr){//Rvale and Lvalue
            //here we change the ptr value to RValue
            if(this!=&ptr){
                if(res) {
                    delete res;
                }
                res = ptr.res;
                ptr.res = nullptr;

            }

            return *this; //return address
            
        }

        T* operator->(){ //operator overloading
            return res;
        }

        T& operator*(){ //* operator means return value provided by that operator using &
            return *res;
        }

        T* get(){
            return res;
        }

        void reset(T* newres=nullptr){
            if(res){
                delete res;
            }
            res=newres;
        }

        ~uniqueptr(){
            if(res){
                delete res;
                res=nullptr;
            }
        }

};




int main(){

    uniqueptr<int> ptr1(new int(2));
    //uniqueptr<int> ptr2(ptr1); //compilation error //copy const
    //uniqueptr<int> ptr3 = ptr1; //compilation error
    uniqueptr<int> ptr4(new int(500));
   // ptr4 = ptr3; //compilation //copy operator
    //uniqueptr<int> ptr3 = move(ptr1); //moving the ownership 
    //ptr4 =move(ptr1);

   // ptr1->func();
    cout<< *ptr1;
    ptr1.get();
    ptr1.reset();

    //destructor
    return 0;
}
