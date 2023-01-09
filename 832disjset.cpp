#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Node{
    public:
    int gr=0;
    // if - = enemy against this num;
    // int enemy=0;
    Node* par=NULL;
    // set <int> enemy;
    set<Node*> child;
    Node(int n){gr=n;}
    Node* finalpar(){
        cout<<'k';
        Node*temp = par;
        
        while(temp!=NULL){ 
            cout<<"y";
            temp=temp->par;
        }
        return temp;
    }
    void changepar(Node* newpar){

    }
    // bool findEnemy(){
    //     Node*temp = par;
    //     while(par!=NULL){ 
    //         temp=temp->par;
    //     }
    //     return temp;
    // }
};

class disjointSet{
    public:
    map<int, Node*> all;
    void befd(int p,int q){
        // if(all.count(p)+all.count(q)==2){ uni(all[p],all[q]); return;}
        if(all.count(p)==0) all[p] = new Node(p);
        if(all.count(q)==0) all[q] = new Node(q);
        uni(all[p],all[q]);
    }
    void uni(Node*p, Node*q){
        if(p==q) return;
        cout<<"here1\n";
        // if(p->gr<0 || (q->gr>0 && p->child.size()<q->child.size())){
        // // if(p->child.size()<q->child.size()){
        //     // merge p to q: iterate over child, iterate over enemy
        //     Node* temp = q;
        //     q = p;
        //     p = temp;
        // } 

        for(Node* i:p->child) q->child.insert(i);
        cout<<"here2\n";
        // q->enemy.clear();
        q->child.clear();
        q->par = p;
        cout<<"here3\n";
        q->gr = p->gr;
    }
    void beenemy(int p,int q){
        if(all.count(p)==0) all[p] = new Node(p);
        if(all.count(q)==0) all[q] = new Node(q);
        if(all.count(-p)==0) all[-p] = new Node(-p);
        if(all.count(-q)==0) all[-q] = new Node(-q);
        Node* ppar = all[p]->finalpar(); // if there is enemy, gr should be -enemy
        Node* qpar = all[q]->finalpar(); 

        uni(ppar,all[-q]); //merge all against q

        uni(qpar,all[-p]); // mereg all against p
    }
};


int main(){
    int n,m,p,q;
    char c;
    
    cin>>n;
    cin>>m;
    disjointSet *ans = new disjointSet();
    // map<int, disjointSet> mapp;
    disjointSet sp,sq;
    for(int i=0;i<m;i++){
        cin>>c>>p>>q;
        if(c=='F'){
            ans->befd(p,q);
        }else{
            ans->beenemy(p,q);
        }
        cout<<"done\n";
        cout<<"here4\n";
        for(auto const a:ans->all){
            cout<<"here5\n";
            cout<<a.first<<": "<<a.second->finalpar()->gr<<'\n';
        }
        // for(int i=1;i<=n;i++) cout<<allgang[i]<<' ';
        // cout<<"\n";
    }
    // int count = 0;
    // set<int> gang;
    // for(int i=1;i<=n;i++){
    //     if(allgang[i]==0) count++;
    //     else gang.insert(allgang[i]);
    // }
    // cout<<count+gang.size();

}