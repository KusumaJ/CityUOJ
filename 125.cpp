#include<iostream>
#include<cmath> 
#include<set>
#include<map>
using namespace std;

map<int, set<int> > ans;

void mergeset(int a, int b){
    if(ans[a]==ans[b]) return;
    if(ans[a].size()<ans[b].size()){
        int temp =a;
        a = b;
        b = temp;
    }
    //merge a to b (bigger)
    for(int x:ans[a]){
        ans[b].insert(x); 
        ans[x] = ans[b];
    }
    ans[a]=ans[b];
    // return b;

}

int main(){
    int t,k,m;
    string strng;
    // cout<<(int)'A';
    cin>>t;
    while(t--){
        cout<<"1";
        char c;
        cin>>c; // one letter
        cout<<c;
        // k = (int)c - 65;
        // set<int> a;
        // a.insert(k);
        // ans[k] = a;
        // cin>>strng; // blank line
        // while(strng!="\n"){
        //     int a = (int) strng[0]-65;
        //     int b = (int) strng[1]-65;
        //     // set<int> tgt = 
        //     mergeset(a,b);
        //     // ans[a] = tgt;
        //     // ans[b] = tgt;
        //     cout<<"done";
        // }
        // set< set<int> > uniquegr;
        // for(auto const& x:ans){
        //     uniquegr.insert(x.second);
        // }
        // cout<<uniquegr.size()<<'\n';
        // cin>>strng;
        // ans.clear();
    }
}