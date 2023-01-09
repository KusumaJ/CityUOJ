// not finished yet
#include<iostream>
using namespace std;


class Stack{
    public:
    int *arr;
    int size;
    // int first=0;
    int index=0;
    Stack(int n){
        arr= new int[n];
        size = n;
    }
    void initial(){
        for(int i=size;i>0;i--) append(i);
        index = size-1;
    }
    void append(int A){
        arr[index++]=A;
    }
    int get(int x){ return arr[x];}
    int pop(){
        // cout<<"PUSH "<<arr[index]<<"\n";
        index--;
        return arr[index+1];
    }
    void push(int x){
        append(x);
        // cout<<"POP "<<x<<"\n";
    }
};

int main(){
    int n,num;
    cin>>n;
    Stack *stackA = new Stack(n);
    Stack *stackR = new Stack(n);
    Stack *stackB = new Stack(n);
    int *B = new int[n];
    stackA->initial();
    for(int i=0;i<n;i++){
        cin>>num;
        B[i]=num;
    }
    int indexB=0;
    while(indexB<n){
        cout<<indexB<<"\n";
        if(stackA->index==0 && stackR->index==0) break;
        else{
            while(B[indexB]==stackR->get(stackR->index-1)){
                stackB->append(stackR->pop());
                indexB++;
            }
            // if(stackA->index!=0)
            stackR->append(stackA->pop());
        }
        // if(stackA->index>0 && stackA->get(stackA->index)!=B[indexB]){
        //     cout<<stackA->size<<"\n";
        //     cout<<"PUSH "<<stackA->get(stackA->index)<<"\n";
        //     stackR->push(stackA->pop());
        // }else{
        //     cout<<"PUSH "<<B[indexB]<<"\n"<<"POP "<<B[indexB]<<"\n";
        //     indexB++;
        //     stackA->pop();
        // }
        // if(stackR->get(stackR->index)==B[indexB]){
        //     cout<<"POP "<<B[indexB]<<"\n";
        //     indexB++;
        //     stackR->pop();
        // }else{

        // }
        // if(stackA->size==0) break;
    }
    if(stackB->index==num+1) cout<<"Yes";
    else cout<<"No";
}