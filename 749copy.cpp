#include<iostream>
using namespace std;

class Node{
    public:
    Node* right=NULL;
    Node* left=NULL;
    int data;
    Node(int n){data = n;}
};


int* subarray(int* arr,int start, int end){
    int* ans = new int[end-start];
    for(int i=0;i<end-start;i++){
        ans[i]=arr[start+i];
    }
    return ans;
};

Node* buildTree(int size, int *pre,int *in){
    if(size<=0) return NULL;
    Node *root = new Node(pre[0]);
    if(size==1) return root;

    int i = 0;
    for(;i<size;i++){
        if(in[i]==pre[0]) break;
    } 

    root->left = buildTree(i,subarray(pre,1,i+1),subarray(in,0,i));
    root->right = buildTree(size-i-1,subarray(pre,i+1,size),subarray(in,i+1,size));
    return root;
};

void post(Node* tree, bool notRoot){
    if(tree->left!=NULL) post(tree->left,true); 
    if(tree->right!=NULL) post(tree->right,true); 
    cout<<tree->data;
    if(notRoot) cout<<" ";
    delete(tree);
};

int main(){
    int t,num;
    int node;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>node;
        int* pre = new int[node];
        int* in = new int[node];
        for(int j=0;j<node;j++){
            cin>>num;
            pre[j]=num;
        }
        for(int j=0;j<node;j++){
            cin>>num;
            in[j]=num;
        }
        Node* root = buildTree(node,pre,in);

        post(root,false);
        cout<<"\n";
    }
    return 0;
}