#include<map>
#include<set>
#include<iostream>
using namespace std;

int* allgang;
//index->real element; content = gr; neg = enemy of (always share)

int findgang(int x){
    cout<<x<<"-"<<allgang[x]<<'\n';
    if(x==allgang[x]) return x;
    if(allgang[x]<0) return allgang[x];
    if(allgang[x]==0){allgang[x]=x; return x;}
    allgang[x] = findgang(allgang[x]);
    return x;
}

void befriend(int p,int q){
    // if(allgang[p])
    cout<<"\n"<<findgang(p)<<" "<<findgang(q)<<"\n";
    if(findgang(p)!=findgang(q)){
        if( findgang(p)>findgang(q) &&findgang(p)!=p) allgang[findgang(p)]=findgang(q);
        else allgang[findgang(q)]=findgang(p);
    }else return;
    //     if(findgang(p)!=0) return;
    //     allgang[p]=p;
    //     allgang[q]=p;
    // }else{
    //     allgang[findgang(p)]=findgang(q);
    // }
}

void beenemy(int p, int q){
    if(allgang[p]==0 && allgang[q]==0){
        if(q<p){allgang[p]=-q;allgang[q]=q;}
        else{allgang[p]=p;allgang[q]=-p;}
    }
    else{
        if(allgang[p]<0)befriend(-allgang[p],q);
        else allgang[findgang(p)]=-1*findgang(q);
        if(allgang[q]<0) befriend(-allgang[q],p);
        else allgang[findgang(q)]=-1*findgang(p);
        // if(findgang(p)<findgang(q)){
        //     int temp = p;
        //     p=q;
        //     q=temp;
        // }
        // if(allgang[p]<0) befriend(-allgang[p],q);
        // else allgang[findgang(p)]=-1*findgang(q);
        // if(allgang[q]<0) befriend(-allgang[q],p);
        // else allgang[findgang(q)]=-1*findgang(p);

    }
}

int main(){
    int n,m,p,q;
    char c;
    allgang = new int[n+1];
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>c>>p>>q;
        if(c=='F'){
            befriend(p,q);
        }else{
            beenemy(p,q);
        }
        for(int i=1;i<=n;i++) cout<<allgang[i]<<' ';
        cout<<"\n";
    }
    int count = 0;
    set<int> gang;
    for(int i=1;i<=n;i++){
        if(allgang[i]==0) count++;
        else gang.insert(allgang[i]);
    }
    cout<<count+gang.size();

}