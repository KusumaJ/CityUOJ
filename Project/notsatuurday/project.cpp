#include<iostream>
#include <chrono>


using namespace std;

class hashTable{
    private:
    int size=0;
    int arrlen = 3;
    int* arr = new int[3]{0};
    public:
    void insert(int i){
        arr[divisionmethod(i)] = i;
        size++;
        if(size>arrlen/2) rehash(2*arrlen);
    }
    void rehash(int newsize){
        int* newarr = new int[newsize];
        for(int i=0;i<arrlen;i++){
            newarr[i] = arr[i];
        }for(int i=arrlen;i<newsize;i++){newarr[i]=0;}
        delete arr;
        arr = newarr;
        arrlen = newsize;
    }
    int search(int x){
        //linear probing + division method
        int ind = x%arrlen;
        while(true){
            if(arr[ind]==x) return ind;
            if(ind == (x-1)%arrlen) break;
            ind = (ind+1)%arrlen;
        }
        return -1;
    }
    int divisionmethod(int i){
        // linear probing + divisionmethod
        int ind = i%arrlen;
        while(true){
            if(arr[ind]==0) return ind;
            if(ind == (i-1)%arrlen) break;
            ind = (ind+1)%arrlen;
        }
        return i%arrlen;
    }
    int del(int i){
        if(search(i)==-1) return -1;
        arr[search(i)]=0;
        tomb[search(i)]=1;
    }
};

int main(){
    chrono::steady_clock sc;   // create an object of `steady_clock` class
    
    string c;
    int n;
    
    auto start = sc.now(); // start timer
    
    hashTable *h = new hashTable();
    while(cin>>c>>n){
    
        if(c[0]=='i'){
            h->insert(n);
        }else if(c[0]=='d'){

        }else{
            // s
            if(h->search(n)==-1) cout<<n<<" does not exist";
            else cout<< h->search(n)<<"\n";
        }
        // cout<<(c[0]=='i');

        auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
        auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
        cout<<"Operation took: "<<time_span.count()<<" seconds !!!";
    }
}