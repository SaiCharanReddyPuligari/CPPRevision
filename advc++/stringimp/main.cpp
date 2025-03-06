#include <bits/stdc++.h>
#include <ostream>
#include <istream>
using namespace std;

class String{
    private:
    char* res; //buffer to catch and store the string coming in
    unsigned int len;

    public:
    String():res(nullptr), len(0){ //the initializer list is compulsory for const (cont int a) and &address values (int &m) & when trying to initialize classes with no default const
    }

    //parameterised
    String (const char* ch){
        len= strlen(ch);
        res= new char[len+1]; // 1 more character '/0' to mark the end of string
        strcpy(res, ch);
    }

    //copy const
    String(const String &str){ //use const to avoid any accidental change errors in between
        //if we are not using &, that is like calling a copy construtor which needs a copy constructor
        //without & throw error
        len = str.len;
        res = new char[len + 1];
        strcpy(res, str.res);
    }
    //construtors are used to initilize values whereas assigments are used to change
   String ( String &&str){//similar to copy
    len=str.len; 
    res=str.res; //pointing rather than copying 
      str = nullptr; //deleting 
      str.len=0;
   }
    //assignment operator, copy is called when string is initialised first, where assignment works
    String &operator= (const String& other){
        //handling self assignment
        if(this!=&other){ //if str3 = str4, this is str3 and other is str4
            //as we are assigning a new value to str3, free the prev memory to avoid leaks
            char *temp = this->res ;//storing str3 value
            len=other.len;
            res= new char[len+1];
            strcpy(res, other.res);
            delete[] temp; //deleting the char array of str3
        }

        return *this;
    }
    //copy and swap idiom(CAS idiom)
        //copying address and swap address
        //alternate to above
        // String & operator = (String str){ //here string comes as copy and its scope only exists for some time
        //     Swap(*this, str); //we swap the address with this and the copy string memeory gets deleted
        //     return *this;
        // }
        // void Swap(String &str1, String &str2){
        //     swap(str1.res, str2.res);
        //     swap(str1.len, str2.len);
        // }

    unsigned int length(){
        return len;
    }
    friend std::ostream& operator<<(std::ostream & out,const String & str); //friend helps in accessing private class members outside class
    friend std::istream& operator>>(std::istream & in,const String & str);

    ~String(){
        if(res){
            delete[] res;
            res = nullptr;
            len = 0;
        }
    }
};
ostream &operator<<(ostream &out, const String & str){

    out<<str.res;
    return out;
}
istream &operator>>(istream &in, const String & str){

    in>>str.res;
    return in;
}

int main(){
    //functions implementing in C++
    String str1; //default constructot
    String str2 = "hello"; //parameterised constructor
    String str3 = str1; //copy construtor //similar to String str5(str1);
    str3=str2; //copy assignment operator
    int len=str2.length();
    cout<<str2; //overloading output operator(<<)
    cin>>str1;  //overloading input operator(<<)
    String str5(str1);

    String str6 = move(str2); //move the ownership to str6 and deleted str2 memeory

}