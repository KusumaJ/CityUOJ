//done dont forget to submit

#include <iostream>

using namespace std;

class maxHeap{
    public:
    // Tree* root;
    int* heap;
    int size=0;
    maxHeap(int n){
        // size = n;
        heap = new int[n];
    }
    void insert(int a){
        heap[size]=a;
        // size++;
        int temp;
        int s = size;
        // cout<<heap[s]<<" "<<heap[(s-1)/2]<<"\n";
        // cout<<(heap[s]>heap[(s-1)/2])<<"\n";
        while(heap[s]>heap[(s-1)/2] && s>0){
            //swap
            temp = heap[s];
            heap[s] = heap[(s-1)/2];
            heap[(s-1)/2] = temp;
            s = (s-1)/2;
        }
        size++;
        // for(int i=0;i<size;i++) cout<<heap[i]<<" ";
        // cout<<"\n";
    }
    void pop(){
        // int value = heap[0];
        heap[0] = heap[size-1];
        int temp = heap[0];
        int hole = 0;
        int child=1;
        while(hole*2+1<size){
            child = hole*2+1;
            
            if(child+1<size-1 && heap[child+1]>heap[child]) child++;
            
            if(heap[child]>temp) heap[hole]=heap[child];
            else break;

            hole = child;
            // hole = (child-1)/2;
            // cout<<hole<<" ";
        }
        // cout<<"**\n";
        heap[hole]=temp;
        size--;
        // for(int i=0;i<size;i++) cout<<heap[i]<<" ";
        // cout<<"\n";
        // return value;
    }
    void print(){
        long long sum=0;
        for(int i=0;i<size;i++) sum+=heap[i];
        cout<<sum<<"\n";
    }
};

int main()
{
    int n,k;
    char c;
    while(cin>>n){
        maxHeap* ans = new maxHeap(n);
        for(int i=0;i<n;i++){
            cin>>c;
            if(c=='a') {
                cin>>k;
                ans->insert(k);
            }else if(c=='p'){
                ans->pop();
            }else if(c=='r'){
                ans->print();
            }
        }
    }
    return 0;
}