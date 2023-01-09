// wait in judge queue
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int n){data=n;}
};

class Store{
    public:
        Node *first = new Node(0);
        Node *last=NULL;
        int max=-1;
        void getNum(int n){
            if(last==NULL){
                if(n>0){
                    last = new Node(n+1);;
                    int i = 1;
                    Node *ite = first;
                    while(i<n){
                        ite->next = new Node(i++);
                        ite = ite->next;
                        // last time ite->data = n-1
                    }
                    ite->next = last;
                    max = n;
                }
                else if(n==0){
                    first->data += 1;
                    max = 0;
                }
            }else if(n==first->data) {first = first->next;}
            else if(n>first->data){
                if(n==last->data){
                    last->next = new Node(n+1);
                    last = last->next;
                    max = n;
                }else if(n>last->data){
                    int i = last->data;
                    Node *ite = last;
                    while(i<n){
                        ite->next = new Node(++i);
                        // ite->data = ++i; // last also increase by 1
                        ite = ite->next;
                        // last time ite->data = n-1
                    }
                    ite->next = new Node(n+1);
                    max = n;
                }else{
                    Node *ite = first;
                    while(ite->next->data<n){
                        ite = ite->next;
                    }
                    // get ite that right before n
                    if(ite->next->data==n){
                        ite->next = ite->next->next;
                    }
                    // if ite->next->data!=n means n is repeated no need to care
                }
                
            } // if n< first then ignore
            // cout<<n<<" "<<first->data<<"\n";
        }
        int getAns(){
            if(first->data<max) return first->data;
            else return max+1;
        }
};

int main(){
    int line;
    int num;
    while(cin>>line){
        Store *Ans = new Store();
        for(int i=0;i<line;i++){
            cin>>num;
            Ans->getNum(num);
        }
        cout<<Ans->getAns()<<"\n";
    }
    return 0; 
}