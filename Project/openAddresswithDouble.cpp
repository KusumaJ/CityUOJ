#include<iostream>
using namespace std;

class openAddress{
    public:
    int currentsize = 7;
    int* table = new int[currentsize];
    bool* tomb;
    int amount=0;
    openAddress(){
        tomb = new bool[currentsize];
        for(int i=0;i<currentsize;i++) tomb[i]=false;
    }
    int hash2(int x){
        return 1+ x%(currentsize-2);
    }
    void rehash(bool t){
        // cout<<"rehash..";
        int size = currentsize;
        if(t) currentsize/=2;
        else currentsize*=2;
        
        int* newtable = new int[size];
        for(int j=0;j<size;j++){
            if(table[j]==0) continue;
            int x = table[j];
            int index = (x*x)%currentsize;
            int i = 1;
            while(newtable[index]!=0){
                //probing -> double hash
                index = hash2(index);
                i++;
            }
            newtable[index] = x;
        }
        // tomb ={};
        table = newtable;
        status();
        tomb = new bool[currentsize];
        for(int i=0;i<currentsize;i++) tomb[i]=false;
        status();
        // tomb = NULL;
        // delete [] table;
        
    }

    void insert(int x){
        // cout<<"x";
        if(amount+1>currentsize/2) cout<<index<<" : ";
            // status();rehash(false);}
        //hash function -> mid square
        int index = (x*x)%currentsize;
        int i = 1;
        
        while(table[index]!=0 || tomb[index]==true){
            
            if(table[index]==x) return;
            if(tomb[index]==true){index=hash2(index);i++; continue;}
            //probing -> quadratic
            index=hash2(index);
            i++;
            if(i>currentsize){rehash(false); i=1;}
            // cout<<index;
        }
        status();
        // cout<<'\n';
        
        // status();
        // cout<<"|||\n";
        amount++;
        // status();
        if(amount<currentsize/8) {rehash(true);insert(x);return;}
        table[index]=x;
    }

    int search(int x){
        int index = (x*x)%currentsize;
        int i = 1;
        
        while(table[index]!=0 || tomb[index]==true){
            //probing -> quadratic
            // cout<<index<<" : ";
            // status();
            if(table[index]==x){return index;}
            index = hash2(index);
            i++;
            if(i>currentsize){rehash(false);return search(x);}
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
        table[exist]=0;
        amount--;
        tomb[exist] = 1;
        return true;
    }


    void status(){
        cout<<"Status: ";
        for(int t=0;t<currentsize;t++){
            cout<<table[t]<<" ";
        }
        cout<<'\n';
        cout<<"TombStatus: ";
        for(int t=0;t<currentsize;t++){
            cout<<tomb[t]<<" ";
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
        hashTable->status();
    }
}