#include<iostream>
#include<cstdio>
using namespace std;

class Stack{
    public:
    int arr[100000];
    int index = 0;
    void append(int num){
        if(num>0) {arr[index]=num; index++;}
    }
    void output(){
        for(int i=index-1;i>=0;i--) cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    int t,n,num;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        Stack *ans=new Stack;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&num);
            ans->append(num);
        }
        ans->output();
    }
}