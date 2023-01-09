#include<iostream>
using namespace std;

class openAddress{
    public:
    int currentsize = 7;
    int* table = new int[currentsize];
    bool* tomb = NULL;
    int amount=0;
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
        // tomb ={};
        tomb = new bool[currentsize];
        for(int i=0;i<currentsize;i++) tomb[i]=false;

        // tomb = NULL;
        // delete [] table;
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
            if(i>currentsize){rehash(); i=1;}
            // cout<<index;
        }
        // cout<<'\n';
        table[index]=x;
        amount++;
    }

    int search(int x){
        int index = (x*x)%currentsize;
        int i =1;
        while(table[index]!=0 || tomb[index]==true){
            //probing -> quadratic
            if(table[index]==x){return index;}
            index=(x*x+i*i)%currentsize;
            i++;
        }
        return -1;
    }

    bool del(int x){
        // if(tomb==NULL){ 
        //     tomb = new bool[currentsize];
        //     for(int i=0;i<currentsize;i++) tomb[i]=false;
        // }
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


int main(){
    
    int n,x;
    string c;
    // cin>>n;
    openAddress *hashTable = new openAddress();
    // while(n--){
    // while(true){
    while(cin>>c>>x){
        if(c[0]=='i'){
            //insert
            hashTable->insert(x);
        }else if(c[0]=='s'){
            //search
            if(hashTable->search(x)!=-1) cout<< x << " was found" << endl;
            else cout<< x << " does not exist" << endl;

        }else{
            //del
            if(hashTable->del(x)) cout<< x << " was deleted successfully" << endl;
            else cout<< x << " does not exist" << endl;

        }
        // hashTable->status();
    }
}