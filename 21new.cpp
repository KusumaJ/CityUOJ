#include<iostream>
using namespace std;
class linkedList{
    public:
        int priority;
        int order;
        linkedList *next;
};

class Queue
{
    // private:
    public:
        linkedList *front = new linkedList;
        linkedList *rear = new linkedList;
        int mincount=0;
        int size=0;
        void appendEle(int n)
        {
            if(size==0){
                front->priority = n;
                front->order = size;
                size++;
                front->next = rear;
                rear = front;
            }else{
                linkedList *temp = new linkedList;
                temp->order = size;
                size++;
                temp->priority = n;
                rear->next = temp;
                rear = temp;
                rear->next = front;
            }
        }
        bool doJob(int p,int m){
            //delete the job with priority p
            if(size==1) {
                return true;
            }else if(size!=0){
                if(front->priority==p){
                    if(front->order==m) return true;
                    else front = rear;
                    
                }else 
                {
                    while(front->next->priority!=p) front = front->next;
                    if(front->next->order==m) return true;
                }
                rear = front;
                front = rear->next->next;
                rear->next = front;
            }
            mincount++;
            size--;
            return false;
        }
};
int main(){
    int t,n,m,j;
    cin>>t;
    for (int k=0;k<t;k++){
        cin>>n>>m;
        //n is #jobs in the queue; m is position of your job
        Queue *num = new Queue;
        // input
        for(int i=0;i<n;i++){
            cin>>j;
            num->appendEle(j);
        }
        linkedList *check = num->front;
        bool reached = false;
        // output -> got some segmentation fault right in this loop
        while(true){
            // pay attention to m
            int currentmax=-1;
            check = num->front;
            int p = 0; //position with max
            while(true){
                if((check->priority)>currentmax) currentmax=check->priority;
                if(currentmax==9){
                    break;
                }
                p++;
                if(p>=num->size) break;
                check = check->next;
            }
            if(num->doJob(currentmax,m)) {cout<<num->mincount+1<<'\n';break;}
        }
    }
}