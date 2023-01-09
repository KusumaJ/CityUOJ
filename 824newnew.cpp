#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node(int x){val=x; next=NULL;}
        int amount = 1;
};
class AnsList{
    public:
        Node* min = NULL;
        Node* max = NULL;
        Node* lessExact = NULL;
        int c;
        int count = 0;
        AnsList(int x){if(x>0)c=x; else c=-x;}
        void add(int x){
            Node* newnode = new Node(x);
            if(min==NULL){
                newnode->next = newnode;
                min = newnode;
                max = min;
            }else{
                if(x<min->val){
                    //add node process
                    newnode->next = min;
                    min = newnode;
                }
                else if(x>max->val){
                    //add node process
                    max->next = newnode;
                    max = newnode;
                }else{
                    Node *temp = min;
                    while(temp->next->val<x){
                            // cout<<x<<abs(temp->val-x)<<"checked\n";
                            // if(abs(temp->val-x)==c) count+=temp->amount;
                        temp =temp->next;
                    }
                    if(x==temp->next->val) temp->next->amount+=1;
                    else{
                        newnode->next = temp->next;
                        temp->next = newnode;
                    }          
                }
            }
            showStatus();  
        }
        void showStatus(){
            cout<<"\nStatus:\n";
            Node* temp = min;
            while(temp!=max){
                cout<<temp->amount;
                temp = temp->next;
            }
            // work hence the counting one not work
            cout<<temp->amount<<"\n";
            temp = min;
            // cout<<"\n";
            while(temp!=max){
                cout<<temp->val;
                temp = temp->next;
            }
            // // work hence the counting one not work
            // cout<<temp->val<<"\n";
            // cout<<"count: "<<count<<"\n";
        }
        int getCount(){
            

            // 
            Node* temp = min;
            // cout<<"\n";
            while(true){
                // cout<<temp->amount;
                if(c==0) count+=temp->amount-1;
                else if(temp==max) break;
                else{
                    Node* innertemp = temp->next;
                    while(true){
                        // cout<<count;
                        // cout<<abs(innertemp->val-temp->val)<<'**';
                        // <<'!='<<c<<"?";
                        if(abs(innertemp->val-temp->val)==c) {
                            
                            // cout<<temp->val<<" "<<count<<"+"<<innertemp->amount*temp->amount<<'\n';
                            count+=innertemp->amount*temp->amount;
                            break;
                        }
                        else if(abs(innertemp->val-temp->val)>c) break;
                        if(innertemp==max) break;
                        innertemp = innertemp->next;
                    }
                    // cout<<temp->val<<innertemp->val<<count<<' ';
                } 
                if(temp==max) break;
                temp = temp->next;
            }
            // cout<<'\n';
            return count;
        }

};

int main(){
    int c,n,count=0,x;
    while(cin>>n){
        cin>>c;
        AnsList* ans = new AnsList(c);
        for(int i=0;i<n;i++){
            cin>>x;
            ans->add(x);
        }
        count+=ans->getCount();
        cout<<count<<"\n";
        // <<"\n";
    }
    return 0;
}