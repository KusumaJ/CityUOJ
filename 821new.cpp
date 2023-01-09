#include<iostream>
#include<vector>
using namespace std;

// class Node{
//     public:
//         int num;   
//         vector<Node *> child;     
//         vector<int> val;
//         Node(int n){
//             num = n;
//         }
//         Node();
// };

// class City{
//     public:
//         int n;
//         vector<long long> ans;
//         City(int x){
//             n=x;
//         }
//         vector<Node *> all;
//         void add(int u,int v,int w){
//             Node* cityu=NULL;
//             Node* cityv=NULL;
//             if(all.size()==0){
//                 cityu = new Node(u);
//                 cityv = new Node(v);
//                 all.push_back(cityu);
//                 all.push_back(cityv);
//             }else{
//                 for(Node* n:all){
//                     if(n->num==u) {cityu=n;}
//                     else if(n->num==v){cityv=n;}
//                     if(cityu!=NULL&&cityv!=NULL) break;
//                 }
//                 if(cityu==NULL) {cityu = new Node(u);all.push_back(cityu);}
//                 if(cityv==NULL) {cityv = new Node(v);all.push_back(cityv);}
//             }

//             cityu->child.push_back(cityv);
//             cityu->val.push_back(w);
//         }
//         void findLongest(){
//             print(all[0],true);
//             long long maxx = 0;
//             for(long long x:ans){
//                 if(maxx<x) maxx = x;
//             }
//             cout<<maxx;
//         }

        
//         long long print(Node* tree,bool root){
//             if(tree->child.empty()) {return 0;}
//             if(tree->val.size()==1) {return print(tree->child[0],false)+tree->val[0];}
//             long long maxx = 0;
//             long long secondmaxx=0;
//             for(int c=0;c<tree->child.size();c++) {
//                 int interest = print(tree->child[c],false) + tree->val[c];
//                 if(interest>maxx){
//                     if(maxx>0) secondmaxx = maxx;
//                     maxx = interest;
//                 }else if(interest>secondmaxx) secondmaxx = interest;
//             }
            
//             ans.push_back(secondmaxx+maxx);
//             if(root) { return maxx+secondmaxx;}
//             return maxx;
//         }    
// };

class Node{
    public:
    int v;
    int weight;
    Node(int ve,int we){
        v = ve; weight = we;
    }

};

class City{
    int n;
    
}


int main(){
    int n,u,v,w;
    int index = 0;
    cin>>n;
    City* city = new City(n);
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        if(u>v){
            int temp = u;
            u = v;
            v = temp;
        }
        city->add(u,v,w);
        
    }
    city->findLongest();
    return 0;
}