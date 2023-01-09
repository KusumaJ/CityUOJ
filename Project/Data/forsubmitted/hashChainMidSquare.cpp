/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237667
 * Submitted at:  2022-12-03 21:15:21
 *
 * User ID:       1985
 * Username:      56718322
 * Problem ID:    886
 * Problem Name:  Hash Table Tester
 */

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

class hashChainwithMidSquareAndLinkedList{
    public:
    Node* table[7919]={NULL};
    void insert(int i){
        if(table[i*i%7919]==NULL) table[i*i%7919] = new Node(i);
        else{
            table[i*i%7919]->addElement(i);
        } 
    }
    Node* search(int i){

        if(table[i*i%7919]==NULL) return NULL;

        if(table[i*i%7919]->val==i) return table[i*i%7919];

        return table[i*i%7919]->searchEle(i);

    
    }
    bool del(int i){
        Node* delnextnode;
        if(table[i*i%7919]==NULL) return false;
        if(table[i*i%7919]->val==i){
            table[i*i%7919]= table[i*i%7919]->next;
            return true;
        }

        delnextnode = search(i); // get node before node to be deleted
        if(delnextnode==NULL) return false;
        delnextnode->next = delnextnode->next->next;
        return true;
        
    }

};

int main(){
    
    int n,x;
    string c;
    // cin>>n;
    hashChainwithMidSquareAndLinkedList *hashTable = new hashChainwithMidSquareAndLinkedList();
    // while(n--){
    // while(true){
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