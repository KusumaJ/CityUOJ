#include<fstream>
#include<iostream>
// #include<string.h>
using namespace std;


class Node{
    //link list implementation
    public:
    int val;
    // Node* next=NULL;
    Node* left = NULL;
    Node* right = NULL;
    Node(int x){val=x;}
};

class BST{
    public:
    BST(int i){root=new Node(i);}
    Node* root;
    // BST(){}
    void insert(int i){
        // assume i not alr exist
        // cout<<"yrgisf";
        // cout<<(root==NULL);
        // if(root == NULL) cout<<"yes";
        // root = new Node(i);
        // else{
            Node* ite = root;
            while(true){
                if(i==ite->val){cout<<i<<" already exists"; return;}
                if(i<ite->val){
                    if(ite->left!=NULL) ite = ite->left;
                    else {ite->left = new Node(i); return;}
                }
                else{
                    if(ite->right!=NULL) ite = ite->right;
                    else {ite->right = new Node(i); return;}
                }
            }
        // }
    }
    // Node
    Node* inordersuccessor(Node* root, int i){
        Node* ite = root;
        if(ite->val>i){
            if(ite->left!=NULL){ 
                if(ite->left->val>i) return inordersuccessor(ite->left,i);
                else return ite->left;
            }else return NULL;
        }else{
            //ite->val<i
            if(ite->right!=NULL && ite->right->val<i){
                // if(ite->right->val>i) return ite;
                return inordersuccessor(ite->right,i);
            }else{
                return ite;
            }
        }

    }
    bool del(Node* ite,int i){
        if(ite==NULL) return false;
        if(i==ite->val) {
            // delete node
            if(ite->left==NULL){
                if(ite->right==NULL) ite = NULL;
                else ite = ite->right;
            }else{
                if(ite->right=NULL) ite = ite->left;
                else{
                    // find inorder successor
                    del(inordersuccessor(root, i),inordersuccessor(root, i)->val);
                }
            }
            return true;
        }
        

        if(i<ite->val) ite = ite->left;
        else ite = ite->right;
        return false;
    }

    void search(int i){
        Node* ite = root;
        while(true){
            if(ite==NULL){cout<<i<<" does not exist";return;}
            if(i==ite->val){cout<<"found";return;}
            else if(i<ite->val){
                if(ite->left==NULL){cout<<i<<" does not exist";return;} 
                ite = ite->left;
            }
            else {
                if(ite->right==NULL){cout<<i<<" does not exist";return;} 
                ite = ite->right;
            }
        }
    }
    void print(Node* ite){
        if(ite->left!=NULL) print(ite->left);
        cout<<ite->val<<" ";
        if(ite->right!=NULL) print(ite->right);
    }
};

class HashTable{
    public:
    BST* bst[97] = {NULL};
    void insert(int i){
        // mid-square method
        if(bst[i*i%97]==NULL){bst[i*i%97]=new BST(i);}
        else bst[i*i%97]->insert(i);
        // cout<<"here";
        // bst[i*i%97]->insert(i);
        // cout<<bst[i*i%97];
        cout<<"done\n";
    }
    void del(int i){
        if(bst[i*i%97]==NULL || bst[i*i%97]->del(bst[i*i%97]->root,i)==false) cout<<i<<" does not exist";
        cout<<"done\n";
    }
    void search(int i){
        if(bst[i*i%97]==NULL) {cout<<i<<" does not exist"; return;}
        bst[i*i%97]->search(i);
        cout<<"done\n";
    }
    void print(int i){
        if(bst[i*i%97]!=NULL) bst[i*i%97]->print(bst[i*i%97]->root);
    }
};

// class HashTableforNode{
    // tabsize = 13;
    // Node* arr[97] = {NULL};
   
    // public:
    //division method with tabsize = 13 -> time limit exceeded
    // void diviinsert(int i){
    //     if(arr[i%13]==NULL) arr[i%13] = new Node(i);
    //     else{
    //         Node* ite = arr[i%13];
    //         while(ite->next!=NULL) ite = ite->next;
    //         ite->next = new Node(i);
    //     }
    // }
    // Node* divisearch(int i){
    //     Node* ite = arr[i%13];
    //     while(ite!=NULL){
    //         if(ite->val==i) return ite;
    //         ite = ite->next;
    //     }
    //     return NULL;
    // }

    // bool dividel(int i){
    //     Node* ite = arr[i%13];
    //     if(ite==NULL) return false;
    //     if(ite->val==i){
    //         arr[i%13] = ite->next;
    //         delete ite;
    //         return true;
    //     }
    //     while(ite->next!=NULL){
    //         if(ite->next->val==i){
    //             ite->next = ite->next->next;
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    //mid-square method with tabsize = 13,97
//     void insert(int i){
//         if(arr[i*i%97]==NULL) arr[i*i%97] = new Node(i);
//         else{
//             Node* ite = arr[i*i%97];
//             while(ite->next!=NULL) ite = ite->next;
//             ite->next = new Node(i);
//         }
//     }

//     Node* search(int i){
//         Node* ite = arr[i*i%97];
//         while(ite!=NULL){
//             if(ite->val==i) return ite;
//             ite = ite->next;
//         }
//         return NULL;
//     }
    
//     bool del(int i){
//         Node* ite = arr[i*i%97];
//         if(ite==NULL) return false;
//         if(ite->val==i){
//             arr[i*i%97] = ite->next;
//             delete ite;
//             return true;
//         }
//         while(ite->next!=NULL){
//             if(ite->next->val==i){
//                 ite->next = ite->next->next;
//                 return true;
//             }
//         }
//         return false;
//     }

// };

int main(){
    // ifstream inFile("input.txt");
    string c;
    int n;
    HashTable* h = new HashTable();
    // while(inFile>>c>>n){
    while(cin>>c>>n){
        // cout<<c<<" "<<n<<"\n";
        if(c[0]=='i'){
            h->insert(n);
            // cout<<"done\n";
        }else if(c[0]=='d'){
            h->del(n);
            // else cout<<n<<" was deleted\n";
        }else{
            // s
            h->search(n);
            // if(h->search(n)==NULL) cout<<n<<" does not exist\n";
            // else cout<< "Exists here: "<<h->search(n)<<"\n";
        }
        cout<<"**";
        h->print(n);
    }
}