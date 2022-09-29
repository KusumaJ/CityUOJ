#include <iostream>

using namespace std;

struct Node{
    int num;
    struct Node *next;
};

bool deletenode(struct Node* beforeTarget){
    cout<<beforeTarget->next->num<<" ";
    beforeTarget->next = beforeTarget->next->next;
    return (beforeTarget==beforeTarget->next);
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
        if(i==n) last = head; // make circular
    }
    last->next = head;

    struct Node* ptr;
    ptr = last;
    while(true){
        for(int i=0;i<m-1;i++) ptr = ptr->next;
        if(deletenode(ptr)) break;
    }
    cout<<ptr->num<<'\n';

}