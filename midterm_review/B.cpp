// not yet finished as well
// terran = human, zerg = alien
// n planets 
#include<iostream>
using namespace std;

//node actually
class node{
    public:
    int strategic;
    int number;
    node *next;
    
    node(){}
    node(int n){strategic=n;}
};

class linkedList{
    public:
    node *first=new node;
    int index=1;
    void append(int n){
        if (index==1){
            first->strategic =n;
            first->next=first; 
        }else{
            node *temp = new node;
            temp->strategic=n;
            temp->number=index;
            if(n<first->strategic){
                temp->next=first;
                first = temp;
            }else{
                if(index==2){
                    first->next=temp;
                    temp->next=NULL;
                }else{
                    node *ite = first;
                    //n>=first->strategic
                    int count = 0;
                    while((ite->next->strategic)<n ){
                        cout<<ite->number<<" "<<ite->strategic<<"\n";
                        if(count==index-2) break;
                        ite=ite->next;
                        count++;
                    }
                    temp->next=ite->next;
                    ite->next = temp;
                }
            } 
        }index++;
    }
    void finish(int m){
        for(int i=0;i<m-1;i++) {
            cout<<first->number<<" "<<first->strategic<<"\n";
            first = first->next;
        }
        cout<<"YAYY: "<<first->number<<" "<<first->strategic<<"\n";
    }
};
//linkedlist actually
// class stack{
//     public:
//     int index=1;
//     linkedList* first = new linkedList(-1);
//     void append(int n){
//         //append to the correct place
//         linkedList* temp = new linkedList;
//         if(first->strategic==-1){
//             first->strategic=n;
//             first->number=index;
//             first->next = temp;
//         }else if(n>first->strategic){
//             linkedList *iter = first;
//             while(iter->next->strategic<=n) iter = iter->next;
//             //stop when iter->next is more than n
//             temp->next = iter->next;
//             temp->number=index;
//             temp->strategic=n;
//             iter->next = temp;

//         }else{
//             temp->number=index;
//             temp->strategic=n;
//             temp->next = first;
//             first = temp;
//         }
//         index++;
//     }
//     void finish(int m){
//         for(int i=0;i<m;i++) first = first->next;
//         cout<<first->number<<" "<<first->strategic<<"\n";
//     }
// };

int main(){
    int t,n,m,num;
    cin>>t;
    for(int i=0;i<t;i++){
        linkedList *Ans = new linkedList;
        cin>>n>>m;
        // the mth-smallest planet is the weakest
        for(int j=0;j<n;j++){
            cin>>num;
            Ans->append(num);
        }
        cout<<"DONE APPEND>>>\n";
        Ans->finish(m);
;    }
}