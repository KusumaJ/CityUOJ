#include<iostream>
using namespace std;


class Node{
    public:
        int val;
        int amount = 0;
        Node* next = NULL;
        Node(int x){val=x;}
        Node(){};
        Node* nextmore = NULL;
        Node* nextless = NULL;

};

class ansList{
    public:
        int c;
        int count;
        ansList(int x){
            if (x >= 0)
                c = x;
            else
                c = -x;
        }; 
        Node* min=NULL;
        Node* max=NULL;
        void add(int x){
            if(max==NULL){
                max = new Node(x);
                max->amount=1;
                max->nextless= new Node(x-c);
                max->nextmore= new Node(x+c);
                max->next = max->nextmore;

                min=max->nextless;
                min->next = max;
                min->nextmore = max;
                
                max->nextmore->nextless = max;
                max=max->nextmore;
            }else{
                if(x<min->amount){
                    
                }
                
            }
            // if(max==NULL){
            //     min = x;
            //     max = x;
            //     min->next = max;
            // }else{
            //     if(x->val<=min->val){
            //         x->next =min;
            //         min = x;
            //     }else if(x->val>max->val){
            //         max->next = x;
            //         max = x;
                    
            //     }else{
            //         Node* temp = min;
            //         while(temp->next->val<x->val) temp = temp->next;
            //         x->next = temp->next->next;
            //         temp->next = x;
            //     }
            // }
        }
        int getCount(){
            // int count = 0;
            // Node* ite1= min;
            // Node* ite2 = min;
            // cout<<(ite1==max);
            // while(ite1!=max){
            //     int internalCount = 0;
                // cout<<ite1->val<<"&"<<ite2->val<<"\n";
            //     while(ite2!=max){
                    
            //         if(ite2->val-ite1->val<C) ite2=ite2->next;
            //         else if(ite2->val-ite1->val==C) internalCount++;
            //         else break;
            //     }
            //     while(ite1->val==ite1->next->val && ite1->next!=max){
            //         count+=internalCount;
            //         ite1=ite1->next;
            //     }
            // }
            return count;
        }
};


int main(){
    int c,n,count=0,x;
    while(cin>>n>>c){
        // int* arr = new int[n];
        ansList* ans = new ansList(c);
        for(int i=0;i<n;i++){
            cin>>x;
            ans->add(x);
            cout<<"done"<<x;
        }
        // Node* temp = ans->min;
        // for(int i=0;i<n;i++){
        //     cout<<temp->val<<" ";
        //     temp =temp->next;
        // }

        count+=ans->getCount();
        cout<<count<<"\n";
        // <<"\n";
    }
    return 0;
}

// #include<iostream>
// using namespace std;
// class Node{
//     public:
//         int val;
//         Node* next;
//         Node(int x){val=x; next=NULL;}
// };
// class AnsList{
//     public:
//         Node* min = NULL;
//         Node* max = NULL;
//         // Node* lessExact = NULL;
//         int c;
//         int count = 0;
//         AnsList(int x){c=x;}
//         void add(int x){
//             Node* newnode = new Node(x);
//             if(min==NULL){
//                 newnode->next = newnode;
//                 min = newnode;
//                 max = min;
//             }else{
//                 Node *temp =min;
//                 if(x<=min->val){
//                     //add node process
//                     newnode->next = min;
//                     min = newnode;
//                 }
//                 else if(x>=max->val){
//                     //add node process
//                     max->next = newnode;
//                     max = newnode;
//                 }else{
//                     while(temp->next->val<x){
//                         if(abs(temp->val-x)==c) count++;
//                         temp =temp->next;
//                     }
//                     newnode->next = temp->next;
//                     temp->next = newnode;
                    
//                 }
//                 while(abs(temp->val-x)>=c){
//                     if(abs(temp->val-x)==c) {
//                         count++;
//                         if(temp==max) break;
//                         while(temp->val == temp->next->val){
//                             count++;
//                             temp=temp->next;
//                             break;
//                         }
//                     }
//                     if(temp==max) break;
//                     temp =temp->next;   
//                 }
//             }
//         }
//         int getCount(){return count;}

// };

// int main(){
//     int c,n,count=0,x;
//     while(cin>>n){
//         cin>>c;
//         AnsList* ans = new AnsList(c);
//         for(int i=0;i<n;i++){
//             cin>>x;
//             ans->add(x);
//         }

//         count+=ans->getCount();
//         cout<<count<<"\n";
//         // <<"\n";
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;
// class AnsList
// {
// public:
//     int c;
//     int count = 0;
//     int length = 0;
//     AnsList(int x)
//     {
//         if (x >= 0)
//             c = x;
//         else
//             c = -x;
//     }
//     int *counting = new int[1];
//     int *countingneg = new int[1];
//     int lengthneg = 0;
//     void add(int x)
//     {
//         if (x >= 0)
//         {
//             if (length <= x)
//             {
//                 if (x == 0)
//                 {
//                     length += 1;
//                     counting[0] = 1;
//                 }
//                 else
//                 {
//                     int *temp = new int[x+c+1];

//                     for (int i = 0; i < length; i++) temp[i] += counting[i];
                    
//                     for (int i = length; i < x+c+1; i++) temp[i] = 0;
        
//                     temp[x] = 1;
//                     length = x+c+1;
//                     counting = temp;
//                 }
//             }
//             else counting[x] += 1;

//             if (x - c >= 0 && length > x - c)
//             {
//                 if (c == 0) count += counting[x - c] - 1;
//                 else
//                 {
//                     count += counting[x - c];
//                     if (length > x + c) count += counting[x + c];
//                 }
//             }
//             if (count < 0) count = 0;
//         }
//         else
//         {
//             x*=-1;
//             if (lengthneg <= x)
//             {
//                 int *temp = new int[x+c+1];
//                 for (int i = 0; i < lengthneg; i++) temp[i] += countingneg[i];
                
//                 for (int i = lengthneg; i < x+c+1; i++) temp[i] = 0;
                
//                 temp[x] = 1;
//                 lengthneg = x+c+1;
//                 countingneg = temp;
//             }
//             else countingneg[x] += 1;
            
//             if (x - c > 0 && lengthneg > x - c)
//             {
//                 if (c == 0) count += countingneg[x - c] - 1;
//                 else
//                 {
//                     count += countingneg[x - c];
//                     if (lengthneg > x + c) count += countingneg[x + c];
//                 }
//             }
//             else if(x-c==0) count+=counting[0];
//             if (count < 0) count = 0;
//         }
//     }
// }

// ;

// int main()
// {
//     int c, n, x, count = 0;
//     while (cin >> n)
//     {
//         cin >> c;
//         AnsList *ans = new AnsList(c);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> x;
//             // cout<<x;
//             ans->add(x);
//         }
//         count += ans->count;
//         cout << count << "\n";
//     }
//     return 0;
// }