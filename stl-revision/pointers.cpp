//pointers holds the address of the another variable
#include <bits/stdc++.h>
using namespace std;

int main(){
    int var=5;
    //pointer syntax
    //datatype* pointername = &variable

    int* p=&var;
    cout<< "variable value "<< var<<endl;
    cout<<"address in pointer " << p<<endl;//p ia address value
    cout<<"pointer pointing to value "<<*p<<endl;//var==*p
    cout<<"ambasent value "<<&var <<endl; //p==&var //both are address

    
    
    return 0;
}