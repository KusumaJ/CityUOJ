#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class gang{
    public:
    // int gangcount;
    // vector<Node*> allgang;
    int* allgang;
    int size;
    gang(int nn){
        size=nn+1;
        // gangcount=nn;
        allgang = new int[nn+1];
        // fill_n(allgang,-1,nn);
    }
    void befriend(int p,int q){
        if(allgang[p]==0 && allgang[q]==0){
            allgang[p]=p;
            allgang[q]=p;
        }else if(allgang[p]==0){
            allgang[p]=allgang[q];
        }else if(allgang[q]==0) allgang[q]=allgang[p];
        else{
            //be fd with all ppl in the gang
            if(allgang[p]<0 && allgang[q]<0){
                befriend(-allgang[p],-allgang[q]);
                // change
            }else if(allgang[p]<0){
                int check = allgang[q];
                for(int i=1;i<size;i++) if(allgang[i]==check) allgang[i]=allgang[p];
            }else{
                
            }
            // int check = allgang[q];
            // for(int i=1;i<size;i++) if(allgang[i]==check) allgang[i]=allgang[p];
        }
    }
    void beEnemy(int p,int q){
        if(allgang[p]==0 && allgang[q]==0){
            allgang[p]=p;
            allgang[q]=-p;
        }else if(allgang[p]==0){
            allgang[p]=-q;
        }else if(allgang[q]==0) allgang[q]=-p;
        else{
            // be fd with all enemy's enemy
            if(allgang[p]<0 && allgang[q]<0){
                befriend(allgang[p],allgang[q]);
                // change

            }else if(allgang[p]<0){
                // change allgang[q] to -p
                int check = allgang[q];
                for(int i=1;i<size;i++) if(allgang[i]==check) allgang[i]=-allgang[p];
            }else{
                //  if(allgang[q]<0) or both >0
                // change allgang[q] to -p
                int check = allgang[p];
                for(int i=1;i<size;i++) if(allgang[i]==check) allgang[i]=-allgang[q];
            }
            // allgang[p]=-allgang[q];
        }
    }
    int countGang(){
        int c = count(allgang+1,allgang+size,0);
        set<int> s(allgang+1,allgang+size);
        return c + s.size();
    }
    
};


int main(){
    int n,m,p,q;
    char c;
    cin>>n;
    cin>>m;
    gang *g = new gang(n);
    for(int i=0;i<m;i++){
        cin>>c>>p>>q;

        if(c=='F'){
            g->befriend(p,q);
        }else{
            g->beEnemy(p,q);
        } 
        // for(int i=0;i<n;i++) cout<<g->allgang[1+i]<<" ";  
        // cout<<"\n";
    }
    // for(int i=0;i<n;i++) cout<<g->allgang[1+i]<<" ";
    
    cout<<g->countGang()<<'\n';
}