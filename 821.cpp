// general tree

#include<iostream>
using namespace std;

class Node{
    public:
        int num;
        Node(int n){
            int* fd = new int[n];
            fd = {0};
        }
        Node();
};

class Street{
    public:
        Node* less;
        Node* more;
        int distance;
        Street(Node*l, Node*m, int d){
            less=l;more=m;distance=d;
        }
};

bool search(Node* city, int n){

}

int main(){
    int n,u,v,w;
    int index = 0;
    cin>>n;
    Node* city[] = new Node[n];
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        if(u>v){
            int temp = u;
            u = v;
            v = temp;
        }
        if(search(city,u)==false){
            city[index] = new Node(u);
        }
    }
    return 0;
}