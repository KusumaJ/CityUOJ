// งง ทมั่วไปหมดแล้ว
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
        Node *first = NULL;
        Node *last=NULL;
        Node *answer=new Node(0);
        void getNum(int n){
            if(n>=0){
                if(first==NULL){
                    //initialize
                    if(n==0){
                        first = new Node(0);
                        last = first;
                        first->next = last;
                        answer->data = 1;
                        answer->next = first;
                    }else{
                        first = new Node(n);
                        last = first;
                        first->next = last;
                        answer->next = first;
                    }
                }else{
                    if(n==answer->data){
                        while(answer->next->data-n==1){
                            if(answer==last) break;
                            if(n>last->data) break;
                            answer = answer->next;
                            n+=1;
                        }answer->data+=1;
                    }else if(n<answer->data){
                        Node *ite = first;
                        while(ite->next->data<n){
                            if(answer==last) break;
                            if(n>last->data) break;
                            answer = answer->next;
                            n+=1;
                        
                        }
                    }
                }

            cout<<"Status: \n";
            Node *ite = first;
            cout<<ite->data<<" "; 
            while(ite!=last){
                cout<<ite->data<<" ";
                ite = ite->next;
            }
            cout<<"\n";
        
        }
        int getAns(){
            return answer->data;
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