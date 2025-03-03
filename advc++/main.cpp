#include <bits/stdc++.h>
#include <execution>
using namespace std;
namespace fs=std::filesystem;

struct Person
{
    int age;
    string name;
    long long no;
};

int sum(int a, int b){
    cout<<"adding two number"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    int res=a+b;
    return res;
}


int main(){

    // Person p{20, "John", 1234567890};//strutural binding//c++17
    // auto [age, name, no] = p;

    // //parallel algorithms using multi-core
    // vector<int> v = {11, 6, 34, 2, 8, 10, 43};
    // sort(execution::par, v.begin(), v.end());//now the sort function uses multiple cores to sort the vector

    // //future and async
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // future<int> ft= async(sum, 8, 9);
    // //sometasks
    // int var=ft.get();
    // cout<<var<<endl;

    // file system
    fs::create_directory("temp");

    fs::copy("scr.txt", "dest.cpp", fs::copy_options::overwrite_existing);

    return 0;
}