#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
    public:
    int weight;
    Node* left=NULL;
    Node* right=NULL;
    int leftt=0;
    int rightt=0;
    // Node(int a,int b){
    //     leftt = a; rightt = b; weight = a+b;
    // }
    Node(Node *a, Node* b){
        left=a; right = b; weight = a->weight+b->weight;
    }
    Node(int a){weight=a;}
    // Node(int a, Node* b){
    //     leftt=a;
    //     right=b;
    //     weight = a + b->weight;
    // }
    // Node(Node* a, int b){
    //     left=a;
    //     rightt = b;
    //     weight = a->weight+b;
    // }
};

struct compareNode{
    bool operator()(Node* a,Node*b){return(a->weight>b->weight);}
};

class huffmanTree{
    public:
    int size;
    int* arr;
    vector<Node*> nodes;
    // bool static compareNode(Node* a,Node*b){return(a->weight<b->weight);}
    priority_queue <Node*, vector<Node*>, compareNode >  pq;
    huffmanTree(int n,int*a){
        size=n;arr=a;
        ans();
    }
    
    void ans(){
        //form simple pq min->max
        for(int i=0;i<size;i++) pq.push(new Node(arr[i]));
        // for(int i=0;i<size;i++) {cout<<pq.top()->weight <<" ";pq.pop();}
        
        while(pq.size()>1){
            Node* a = pq.top();
            // cout<<pq.top()->weight<<("$");
            pq.pop();
            // cout<<pq.top()->weight<<" ";
            pq.push(new Node(a,pq.top()));
            pq.pop();
        }

    }
};

int gothru(Node* x, int level,int count){
    if(x->left==NULL && x->right==NULL) return count+(x->weight)*level;
    int ans = count;
    if(x->right!=NULL) ans+=gothru(x->right,level+1,count);
    if(x->left!=NULL) ans+=gothru(x->left,level+1,count);
    return ans;
    // count+=(level+1)*x->leftt;
    // if(x->left!=NULL)
    //     count+=gothru(x->left,level+1);
    
    // count+=(level+1)*x->rightt;
    // if(x->right!=NULL)
    //     count+=gothru(x->right,level+1);

    // cout<<level<<"&"<<x->weight<<":"<<count<<"-     ";

    // if(count==0) return (level)*x->weight;
    // return count;
}

int main(){
    int n,k;
    while(cin>>n){
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>k;
            int j = i-1;
            for(;j>=0;j--){
                if(k<arr[j]){
                    arr[j+1]=arr[j];
                }else {break;}
            }
            arr[j+1]=k;
        }
        huffmanTree *ans = new huffmanTree(n,arr); 
        cout<<gothru(ans->pq.top(),0,0)<<'\n';
    }
    return 0;
}