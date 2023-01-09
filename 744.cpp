#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    int n,m;
    for(int t=0;t<T;t++){  
        cin>>n;
        int *stackA = new int[n];
        for(int nn=0;nn<n;nn++) cin>>stackA[nn];
        // for(int nn=0;nn<n;nn++) cout<<stackA[nn];
        cin>>m;
        for(int mm=0;mm<m;mm++){
            int *stackB = new int[n];
            int *stackS = new int[n];
            for(int nn=0;nn<n;nn++) cin>>stackB[nn];
            // checking process
            // int len = 0;
            // int sizeA = n;
            // int checkB=0;
            // int i = 0;
            // while(i<n){
            //     stackS[i] = stackA[n-i-1];
            //     if(stackS[i]==stackB[checkB]) checkB++;
            //     else i++;
            // }
            // cout<<(checkB==n);
            int ite = 0;
            int countS = 0;
            
            while(true){

                cout<<"CountS: "<<countS<<"  ite: "<<ite<<"\n";
                for(int i =0;i<n;i++){
                    cout<<"A"<<stackA[i]<<" ";
                }
                cout<<"\n";
                for(int i =0;i<n;i++){
                    cout<<"B"<<stackB[i]<<" ";
                }
                cout<<"\n";
                for(int i =0;i<n;i++){
                    cout<<"S"<<stackS[i]<<" ";
                }
                // cout<<"\n"<<stackA[n-ite-1]<<" "<<stackB[ite]<<" "<<stackS[countS]<<" "<<stackA[n-countS-ite];
                if(countS+ite>=1) cout<<"\n"<<stackA[n-ite-1]<<" "<<stackB[ite]<<" "<<stackS[countS]<<" "<<stackA[n-countS-ite];
                cout<<"\n";
                while(stackA[n-ite-1]==stackB[ite]){
                    // n=4;
                    *stackB = *(stackB+1);
                    ite++;
                    cout<<"hceked1\n";
                    if(stackA[n-ite-2]!=stackB[ite]) ite--;
                }
                if(ite==n-1) break;
                while(stackS[countS]==stackB[ite]){
                    *stackB = *(stackB+1);
                    countS--;
                    cout<<"checkced2\n";
                }
                *(stackS+countS) = stackA[n-countS-ite];
                countS++;
                if(countS==n) break;
                
            }
            // cout<<ite;
        }
    }
    return 0;
}
