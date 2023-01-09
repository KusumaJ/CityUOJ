
//mul method with separate chaining
#include<iostream>
using namespace std;

class Node{
    public:
    int size;
    int val;
    Node* next;
    void addElement(int i){
        if(val==i) return;
        if(next==NULL) next=new Node(i);
        else next->addElement(i);
    }

    //return pre element
    Node* searchEle(int i){
        if(next==NULL) return NULL;
        if(next->val==i) return this;
        return next->searchEle(i);
    }
    Node(int i){val=i;}
};

class hashChainwithMulMethodAndLinkedList{
    public:
    Node* table[997]={NULL};
    int f(int x) {
        double c = x*3.1415926/3.0;
        return (c - (long) c)*997;
        // return 997*((x*3.1415926/3.0)%1) ;
    }
    void insert(int i){
        if(table[f(i)]==NULL) table[f(i)] = new Node(i);
        else table[f(i)]->addElement(i);
    }
    Node* search(int i){

        if(table[f(i)]==NULL) return NULL;

        if(table[f(i)]->val==i) return table[f(i)];

        return table[f(i)]->searchEle(i);

    
    }
    bool del(int i){

        if(table[f(i)]==NULL) return false;
        if(table[f(i)]->val==i){
            table[f(i)]= table[f(i)]->next;
            return true;
        }

        Node* delnextnode = search(i); // get node before node to be deleted
        if(delnextnode==NULL) return false;
        delnextnode->next = delnextnode->next->next;
        return true;
        
    }

};

int main(){
    
    int n,x;
    string c;
    // cin>>n;
    hashChainwithMulMethodAndLinkedList *hashTable = new hashChainwithMulMethodAndLinkedList();

    while(cin>>c>>x){
        if(c[0]=='i'){
            //insert
            hashTable->insert(x);
        }else if(c[0]=='s'){
            //search
            if(hashTable->search(x)!=NULL) cout<< x << " was found" << endl;
            else cout<< x << " does not exist" << endl;

        }else{
            //del
            if(hashTable->del(x)) cout<< x << " was deleted successfully" << endl;
            else cout<< x << " does not exist" << endl;

        }
    }
}