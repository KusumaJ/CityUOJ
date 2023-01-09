#include<iostream>
#include<vector>
using namespace std;

class gang{
    public:

    vector<int> gr;
    int maxgang;
    int* enemy;
    gang(int n){
        maxgang=n;
        enemy = new int[n];
        for(int i=0;i<=n;i++) gr.push_back(i);
    }
    void befriend(int p,int q){
        if(getgr(p)!=getgr(q)){
            gr[getgr(p)] =  getgr(q); //change gr
            maxgang--;
        }
    }
    void beenemy(int p,int q){
        if(enemy[q]) befriend(p,enemy[q]);
        else enemy[q]=p;

        if (enemy[p]) befriend(q,enemy[p]);
        else enemy[p] = q;
    }

    int getgr(int p){
        if(p==gr[p]) return p;
        else gr[p] = getgr(gr[p]); 
        return gr[p];
    }

    void ans(){
        cout<<maxgang<<'\n';
    }

    void status(){
        cout<<"enemy: ";
        for(int i=0;i<gr.size()-1;i++) cout<<enemy[i]<<" ";
        cout<<"\nGroup: ";
        for(int i:gr) cout<<i<<" ";
    }
};

int main(){
    int n,m,p,q;
    char c;
    cin>>n;
    cin>>m;
    gang *ans = new gang(n);
    for(int i=0;i<m;i++){
        cin>>c>>p>>q;
        if(c=='F'){
            ans->befriend(p,q);
            
        }else{
            ans->beenemy(p,q);
        }
        // ans->status();
    }
    ans->ans();
}