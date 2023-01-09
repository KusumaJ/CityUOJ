#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<int, set<int> > befriend(map<int, set<int> > allgang,int p,int q){
    if(allgang.empty() || allgang.count(p)+allgang.count(q)==0){
        set<int> temp;
        temp.insert(p);
        temp.insert(q);
        allgang[p]=temp;
        allgang[q]=temp;
    }else{
        if(allgang[p].count(q)>0) return allgang;
        if(allgang.count(q)!=0){
            for(int x:allgang[q]) allgang[p].insert(x);
            allgang[q] = allgang[p];
        }
        else{
            allgang[p].insert(q);
            allgang[q] = allgang[p];
        }
    }
    return allgang;
}

map<int, set<int> > beenemy(map<int, set<int> > allgang, int p,int q){
    if(allgang.empty() || allgang.count(p)+allgang.count(q)==0){
        set<int> setp,setq;
        setp.insert(p);
        setp.insert(-q);
        allgang[p]=setp;
        setq.insert(q);
        setq.insert(-p);
        allgang[q]=setq;
    }else{
        if(allgang[q].size()==0) allgang[q].insert(q);
        if(allgang[p].size()==0) allgang[p].insert(p);
        
        vector<int> fdq;
        vector<int> fdp;

        for(const auto &m:allgang){
            if(m.first==q || m.first==p) continue;
            if(m.second.count(-p)>0) fdq.push_back(m.first);
            if(m.second.count(-q)>0) fdp.push_back(m.first);
        }
        for(int i:fdq){
            allgang = befriend(allgang,i,q);
        }
        for(int i:fdp){
            allgang = befriend(allgang,i,p);
        }
        allgang[q].insert(-p);
        allgang[p].insert(-q);
    }
    return allgang;
}

int main(){
    int n,m,p,q;
    char c;
    cin>>n;
    cin>>m;
    int j;
    
    map<int, set<int> > allgang;
    for(int i=0;i<m;i++){
        cin>>c>>p>>q;
        if(c=='F'){
            allgang = befriend(allgang,p,q);
        }else{
            allgang = beenemy(allgang,p,q);
        } 
        // for(const auto &m:allgang){
        // cout<<m.first<<":";
        // for(int i:m.second) cout<<i<<" ";
        // cout<<'\n';
        // }
    }

    int count = 0;
    set<int>counted;
    for(int i=1;i<=n;i++){
        int oldlen = counted.size();
        // cout<<i<<": ";
        for(auto itr:allgang[i]){
            if(counted.count(itr)>0) break;
            counted.insert(itr);
            // cout<<itr<<' ';
        }
        // cout<<'\n';
        // allgang[i].clear();
        if(counted.size()!=oldlen)
        count+=1;
    }

    cout<<count;

    return 0;
}
