#include<cstdio>
#include<iostream>
using namespace std;
class node{
    public:
        int val;
        node *next;
};

class sortList
{
    // private:
    public:
        node *front = new node;
        node *rear = new node;
        int mincount=0;
        int size=0;
        void append(int n)
        {
            if(size==0){
                front->val = n;
                size++;
                rear = front;
                front->next = rear;
            }else{
                node *temp = new node;
                size++;
                temp->val = n;
                if(n>=rear->val){
                    rear->next = temp;
                    rear = temp;
                    rear->next = front;}
                else if(n<=front->val){
                    temp->next = front;
                    front = temp;
                    rear->next = front;
                }else{
                    node *check = front;
                    while(n>check->next->val) check = check->next;
                    temp->next = check->next;
                    check->next = temp;
                }
            }
        }
};

int main(){
    int k,size,num;
    scanf("%d",&k);
    sortList *ans = new sortList;
    for(int i=0;i<k;i++){
        scanf("%d",&size);
        //  = new sortList(size);
        for(int j=0;j<size;j++){
            scanf("%d",&num);
            ans->append(num);
        }
    }
    // printf("*****\n");
    while(ans->front!=ans->rear) {printf("%d ",ans->front->val);ans->front=ans->front->next;} 
    // ans->show();
}

// void append(int n){
//         cout<<"readhed";
//         if(first==last){
//             cout<<"heregon\n";
//             // first->data = n;
//             // first->next = last;
//             // cout<<"done\n";
//         }else{
//             cout<<"here\n";
//             // node*temp = new node;
//             // temp->data=n;
//             // if(n<=first->data){
//             //     cout<<"case1\n";
//             //     temp->next = first;
//             //     last->next = temp;
//             //     first = temp;
//             // }else if(n>last->data){
//             //     cout<<"case2\n";
//             //     last->next = temp;
//             //     temp->next = first;
//             //     last = temp;
//             // }else{
//             //     cout<<"case3\n";
//             //     node*check  =first;
//             //     while(n>check->next->data) check=check->next;
//             //     check->next = temp;
//             //     temp->next = check->next->next;
//             // }
//             size++;
//         }
//     }