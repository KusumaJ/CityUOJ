#include<iostream>
using namespace std;
class node{
    public:

};
class linkedList{
    public:
    node* top = new node;
    node* bottom = new node;
    void play(char a, char b, int n){
        if(a=='I'){
            if(b=='H')
            else
        }else if (a=='R'){
            if(b=='H')
            else
        }else{
            
        }
    }
};
int main(){
    char a,b;
    int n,t,I;
    linkedList* game = new linkedList;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>I;
        for(int i=0;i<I;i++){
            cin>>a>>b>>n;
            game->play(a,b,n);
        }
    }
}