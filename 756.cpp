// not yet done

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node* right=NULL;
    Node* left=NULL;
    int data;
    Node(int n){data = n;}
    Node(){data=-1;}
};

// class 

int main(){
    int n,num;
    char ope;
    while(n){
        cin>>n;
        // Node* root = new Node;
        bool exist = false;
        vector<int> v;
        int* members = new int[n]{};
        int index = 0;
        for(int i=0;i<n;i++){
            cin>>ope>>num;
            if(ope=='a' && exist==false) members[index++]=num;
            else{
                if(exist==false) {
                    vector<int> v(members,members+index);
                    make_heap(v.begin(),v.end());
                    cout<<0;
                }
                else{
                    exist = true;
                    if(ope=='a') v.push_back(num);
                    else if (ope=='p') v.pop_back();
                    else{
                        cout<<v[0];
                        for(int i=1;i<v.size();i++){
                            cout<<' '<<v[i];
                        }
                    }
                }
            }
        }

    }
    return 0;
}