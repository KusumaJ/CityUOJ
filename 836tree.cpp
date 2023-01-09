#include<iostream>
using namespace std;

// class Node{
//     public:
//     int val;
//     Node(int v){val=v;}
// };

class Tree{
    public:
    int root=NULL;
    Tree* left=NULL;
    Tree* right=NULL;
    int ans=0;
    Tree(int v){root = v;}
    void add(int v){
        if(v==ans) ans++;
        if(v<root){
            if(left==NULL) left = new Tree(v);
            else left->add(v);
        }else if(v>root){
            if(right==NULL) right = new Tree(v);
            else right->add(v);
        }
    }
};

void check(Tree* tree,Tree* root){
    if(tree->left!=NULL) check(tree->left,root);
    if(tree->root==root->ans) root->ans++;
    if(tree->right!=NULL) check(tree->right,root);
}

void print(Tree* tree){
    if(tree->left!=NULL) print(tree->left);
    cout<<" "<<tree->root<<" ";
    if(tree->right!=NULL) print(tree->right);
}


int main(){
    int n,v;
    while(cin>>n){
        cin>>v;
        Tree* ans = new Tree(v);
        for(int i=0;i<n-1;i++){
            cin>>v;
            ans->add(v);
        }
        check(ans,ans);
        cout<<ans->ans<<'\n';
    }
}