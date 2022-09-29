#include <iostream>

using namespace std;

struct Node{
    int num;
    struct Node *next;
};

void deletenode(struct Node* beforeTarget){
    cout<<beforeTarget->next->num<<" ";
    beforeTarget->next = beforeTarget->next->next;
}

int main(){
    int n,m;
    cin>>n>>m;
    struct Node* head = NULL;
    struct Node* last = NULL;
    for(int i=n;i>0;i--){
        struct Node* nextnode = (struct Node*) malloc(sizeof(struct Node));
        nextnode-> num = i;
        nextnode->next = head;
        head = nextnode;
        if(i==n) last = head;
    }
    last->next = head;
    
    // cout<<last->num;
    // cout<<last->next->num<<'\n';


    struct Node* ptr;
    ptr = last;

    int debugger = 30;
    while (ptr != ptr->next) {
        for(int i=0;i<m-1;i++) ptr = ptr->next;
        deletenode(ptr);
        debugger--;
        if(debugger==0) break;
    }

    // for(int i=0;i<2*n;i++){
    //     cout<<ptr->num<<" ";
    //     ptr = ptr->next;
    // }

}