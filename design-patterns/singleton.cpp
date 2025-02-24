#include <bits/stdc++.h>
using namespace std;

class Singleton{
   static Singleton* instance;
    Singleton(){}; //Default Constructor
    ~Singleton(){}; //Default Destructor
    int value {0};
    Singleton(Singleton &other) = delete; // Copy Constructor
    void operator = (const Singleton &) = delete; //Assignement operator

   public:

   static Singleton* getInstance(){
    if(instance==nullptr){
        instance=new Singleton();
    }
    return instance;
   }

   void setValue(int _value){
      value=_value;
   }

   int getValue(){
    return value;
   }
};

Singleton* Singleton::instance=nullptr;

int main(){
    Singleton* singleton = singleton->getInstance();
    //singleton->setValue(100);
    cout<<singleton->getValue()<<endl;
}