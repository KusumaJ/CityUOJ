#include <iostream> 
#include <fstream>
#include <limits>
#include <random> 
#include <unordered_set> 
#include <chrono>

using namespace std;

// for chaining
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

const int tablesize = 97;
char funct = 'a';

int f(int i) {
    if(funct=='a') return i%tablesize;
    if(funct=='b') return i*i%tablesize;
    if(funct=='c') {
        double c = i*3.1415926/3.0;
        return (c - (long) c) * tablesize;
    }
    if(funct=='d'){
        int summ=0;
        while(i>0){
            summ+=(i%10);
            i/=10;
        }
        return summ%tablesize;
    }
}

class hashChain{
    public:
    Node* table[tablesize] = {NULL};
    void insert(int i){
        if(table[f(i)]==NULL) table[f(i)] = new Node(i);
        else{
            table[f(i)]->addElement(i);
        } 
    }
    Node* search(int i){

        if(table[f(i)]==NULL) return NULL;

        if(table[f(i)]->val==i) return table[f(i)];

        return table[f(i)]->searchEle(i);

    
    }
    bool del(int i){
        Node* delnextnode;
        if(table[f(i)]==NULL) return false;
        if(table[f(i)]->val==i){
            table[f(i)]= table[f(i)]->next;
            return true;
        }

        delnextnode = search(i); // get node before node to be deleted
        if(delnextnode==NULL) return false;
        delnextnode->next = delnextnode->next->next;
        return true;
        
    }

};

//for open addressing
class openAddress{
    public:
    int currentsize = 7;
    int* table = new int[currentsize];
    bool* tomb = NULL;
    int amount = 0;
    openAddress(){
        tomb = new bool[currentsize];
        for(int i=0;i<currentsize;i++) tomb[i]=false;
    }
    void rehash(){
        // cout<<"rehash..";
        currentsize*=2;
        
        int* newtable = new int[currentsize];
        
        for(int j=0;j<currentsize/2;j++){
            if(table[j]==0) continue;
            int x = table[j];
            int index = (x*x)%currentsize;
            int i = 1;
            while(newtable[index]!=0){
                //probing -> quadratic
                index = (x*x+i*i)%currentsize;
                i++;
            }
            newtable[index] = x;
        }

        tomb = new bool[currentsize];
        for(int i=0;i<currentsize;i++) tomb[i]=false;

        table = newtable;
    }
    void insert(int x){
        // cout<<"x";
        if(amount+1>currentsize/2) {rehash();}
        //hash function -> mid square
        int index = (x*x)%currentsize;
        int i = 1;
        while(table[index]!=0 || tomb[index]==true){
            if(table[index]==x) return;
            if(tomb[index]==true){index=(x*x+i*i)%currentsize;i++; continue;}
            //probing -> quadratic
            index=(x*x+i*i)%currentsize;
            i++;
            if(i>currentsize){rehash(); i=0;}
            // cout<<index;
        }
        // cout<<'\n';
        table[index]=x;
        amount++;
    }

    int search(int x){
        // cout<<"s ";
        int index = (x*x)%currentsize;
        int i =1;
        while(table[index]!=0 || tomb[index]==true){
            //probing -> quadratic
            if(table[index]==x){return index;}
            index=(x*x+i*i)%currentsize;
            i++;
            if(i>currentsize) break;
        }
        return -1;
    }

    bool del(int x){
        int exist = search(x);
        if(exist==-1) return false;
        tomb[exist]=true;
        table[exist]=0;
        amount--;
        return true;
    }

    void status(){
        cout<<"Status: ";
        for(int t=0;t<currentsize;t++){
            cout<<table[t]<<" ";
        }
        cout<<'\n';
    }

};


int main(int argc, char **argv)
{

    chrono::steady_clock sc;   // create an object of `steady_clock` class
    
    ifstream inputFile("inputforchaining.txt"); // input from the input.txt 
    ofstream outputFile("outputforchaining.txt"); // output into the output.txt
    
    string line;
    int x;
    // hashChain *hashTable = new hashChain();
    openAddress *hashTable = new openAddress();
    auto start = sc.now(); // start timer
    cout<<"start...";
    if(inputFile.is_open()){
        while(inputFile){
            inputFile>>line>>x;
            if(line[0]=='i'){
                //insert
                // cout<<"i ";
                hashTable->insert(x);
                
            }else if(line[0]=='s'){
                //search
                // cout<<"s ";
                if(hashTable->search(x)!=NULL) outputFile<< x << " was found" << endl;
                else outputFile<< x << " does not exist" << endl;
                
            }else{
                //del
                // cout<<"d ";
                if(hashTable->del(x)) outputFile<< x << " was deleted successfully" << endl;
                else outputFile<< x << " does not exist" << endl;
                
            }
        }
    }

    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast <chrono::duration <double> > (end - start);   // measure time span between start & end
    cout<<time_span.count();
}