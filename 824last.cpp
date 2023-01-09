#include<iostream>
#include<map>
using namespace std;


int main(){
    long long int c,n,count,x;
    while(cin>>n){
        cin>>c;
        map<long long int,long long int> ans;
        count = 0;
        // for(int i=1;i<=n;i++) ans[i]=0;
        for(int i=0;i<n;i++){
            cin>>x;
            ans[x]++;
            if(c!=0){
                count+=ans[x-c];
                count+=ans[x+c];
            } else count = count - (ans[x]-1)*(ans[x]-1) + (ans[x])*ans[x];
            // cout<<count<<"\n";
        }
        cout<<count<<"\n";
    }
    return 0;
}
