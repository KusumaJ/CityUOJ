#include <iostream>

using namespace std;

int main(){
    int n,q,o;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>q;
    int num1,num2;
    for(int i=0;i<q;i++){
        cin>>o>>num1;
        if(o==1){
            cin>>num2;
            // cout<<"Num1: "<<num1<<"; Num2: "<<num2<<"\n";
            int* tempo = new int [n+1];
            int j=0;
            for(;j<num1;j++){
                tempo[j]=arr[j];
            }
            tempo[j]=num2;
            for(++j;j<n+1;j++) tempo[j]=arr[j-1];
            arr = tempo;
            n+=1;
        }else if(o==2){
            int* tempo = new int [n-1];
            int j=0;
            for(;j<num1-1;j++) tempo[j]=arr[j];
            for(;j<n-1;j++) tempo[j]=arr[j+1];
            arr = tempo;
            n-=1;
        }else if(o==3){
            cin>>num2;
            int* tempo = new int [num2-num1+1];
            for(int i=0;i<=num2-num1;i++){
                tempo[num2-num1-i] = arr[num1+i-1];
            }
            for(int i=num1-1;i<num2;i++) {
                arr[i]=tempo[i-num1+1];
            }

        }else{
            cout<<arr[num1-1]<<'\n';
        }
        
    }
}