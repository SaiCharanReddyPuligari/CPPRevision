#include <bits/stdc++.h>
using namespace std;

struct Character{
    string name;
    int x;
    int y;
    Character(const string _name) : name (_name){}

    void move(int _x, int _y){
          x=_x;
          y=_y;
    }
};

class Command{
    public:
    virtual void execute(Character & c)=0;
    virtual void undo(Character & c)=0;
};

class Move: public Command{
     public:
     void execute(Character & c){
        cout<<c.name<<" made a move"<<endl;
     }
     void undo(Character & c){
        cout<<c.name<<" undid a move"<<endl;
     }
};

int main(){

    Character sai("sai");
    vector<Command*> C_queue;
    Move* m1= new Move;
    C_queue.push_back(m1);
    Move* m2= new Move;
    C_queue.push_back(m2);
    Move* m3= new Move;
    C_queue.push_back(m3);
    Move* m4= new Move;
    C_queue.push_back(m4);

    for(int i=0;i<4;i++){
        C_queue[i]->execute(sai);
    }
    for(int i=C_queue.size()-1;i>=0;i--){
        C_queue[i]->undo(sai);
    }
    return 0;
}