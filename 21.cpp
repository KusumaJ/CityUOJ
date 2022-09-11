#include<iostream>

using namespace std;

int max(int* arr,int size){
    int maxx=-1;
    int maxind;
    for (int i=0;i<size;i++){
        if(arr[i]>maxx) {maxx=arr[i];maxind=i;}
        if (maxx==9) return i;
    }
    return maxind;
}

int main(){
    int t,n,m;
    cin>>t;
    for (int j=0;j<t;j++){
        cin>>n>>m;
        int* arr = new int[n];
        // input
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // output
        int count=0;
        while(true){
            count++;
            // cout<<max(arr,n)<<" "<<arr[max(arr,n)]<<" "<<m<<"\n";
            if(m==max(arr,n)){
                cout<<count<<'\n';
                break;
            }else{
                arr[max(arr,n)]=-1;
                // rearrange the queue
                int last = arr[0]; 
                for (int i=0;i<n;i++) arr[i]=arr[i+1];
                arr[n-1]=last;
                if(m!=0) m--;                
            }
        }
    }
    return 0;
}