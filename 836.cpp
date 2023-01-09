//not yet finished
#include<iostream>
using namespace std;
class linkedList{
    public:
        int data;
        linkedList *next;
        linkedList(int n){data=n;}
        linkedList(){}
};

class Ans{
    public:
    linkedList *smallest = new linkedList(-1);
    linkedList *last = new linkedList();
    linkedList *ans = new linkedList(0);
    void append(int n){
        if(smallest->data==-1){
            // cout<<"base case\n";
            smallest->data=n;
            smallest->next = last;
            last = smallest;
            ans->next = smallest;
            if(n==0) ans->data=1;
        }else{
            linkedList *newOne = new linkedList(n);
            if(n>=last->data){
                last->next = newOne;
                newOne->next = smallest;
                last = newOne;
            }
            else{
                //if n<ans->data means it alr exist and we dont care
                if(n==ans->data){
                    
                }else if(n>ans->data){

                }
                // if(n<smallest->data){
                //     newOne->next=smallest;
                //     last->next=newOne;
                //     smallest=newOne;
                //     ans->next = smallest;
                // }else{
                // }
                // else if(n>=ans->data){
                //     linkedList *check;
                //     // int originalN = n;
                //     smallest->data=n;
                //     smallest->next=ans->next;
                //     if(n==ans->data){
                //         //if n<ans->data then it should be repeated
                //             //shift ans to next possible ans
                //         while(true){
                //             ans=ans->next; //refer to next real element 
                //             if(ans==last){ n++; break; }
                //             if(n<ans->data) break; 
                //             n++;
                //         }
                //         linkedList *temp = new linkedList(n);
                //         temp->next=ans;
                //         ans = temp;
                //         check = ans;

                //     }else{
                //         // n>ans->data
                //         check = ans;
                //         while(check->next->data<n){check = check->next;}
                //         //get the check->next->data > n
                //         check->next=newOne;
                //         newOne->next=check->next->next;
                //     }
                //     // newOne->next=check->next;
                //     // check->next = newOne;
                // }
            }
        }
        if(n==ans->data){
            //shift ans to next possible ans
            while(true){
                ans=ans->next; //refer to next real element 
                if(ans==last){ n++; break; }
                if(n<ans->data) break; 
                n++;
            }
            linkedList *temp = new linkedList(n);
            temp->next=ans;
            ans = temp;

        }
    }
    void findAnswer(){cout<<ans->data<<"\n";}
};

int main(){
    int line;
    int num;
    while(cin>>line){
        Ans *answer = new Ans;
        for(int i=0;i<line;i++){
            cin>>num;
            answer->append(num);
        }
        answer->findAnswer();
        delete answer;
    }
}