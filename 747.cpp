#include<iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std;

int main(){
    int t,n,k,m;
    cin>>t;
    while(t--){
        deque< vector<int> > q;
        cin>>n>>m;
        //length and param
        for(int i=0;i<n;i++){
            cin>>k;
            vector<int> x;
            x.push_back(k);
            x.push_back(i+1);
            q.push_back(x);
        }

        deque< vector<int> >tmp;
        // int count = 30;
        int maxindd;
        while(n--){
            int mm=m;
            int maxx = q.front()[0];

            while(mm--){
                if(q.size()==0) break;
                if(q.front()[0]>=maxx){maxx=q.front()[0]+1; maxindd=q.front()[1];}
                
                tmp.push_back(q.front());
                q.pop_front();
            }

            while(!tmp.empty()){
                // cout<<tmp.front()[0]<<" "<<tmp.front()[1]<<" ";
                if(tmp.front()[1]==maxindd) {cout<<tmp.front()[1];if(n!=0)cout<<" ";}
                else {tmp.front()[0]-=1; q.push_back(tmp.front());}
                tmp.pop_front();
            }
            // count--;
        }cout<<'\n';
        
    }
}