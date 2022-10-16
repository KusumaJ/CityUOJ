#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    int n,m;
    for(int t=0;t<T;t++){  
        cin>>n;
        int *stackA = new int[n];
        int *stackB = new int[n];
        int *stackS = new int[n];
        for(int nn=0;nn<n;nn++) cin>>stackA[nn];
        // for(int nn=0;nn<n;nn++) cout<<stackA[nn];
        cin>>m;
        for(int mm=0;mm<m;mm++){
            for(int nn=0;nn<n;nn++) cin>>stackB[nn];
            // checking process
            int len = 0;
            int sizeA = n;
            int checkB=0;
            int i = 0;
            while(i<n){
                stackS[i] = stackA[n-i-1];
                if(stackS[i]==stackB[checkB]) checkB++;
                else i++;
            }
            cout<<(checkB==n);
        }
    }
    return 0;
}
