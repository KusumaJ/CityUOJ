#include <iostream>
using namespace std;

class Node
{
public:
    Node(int n) { num = n; next = NULL;}
    int num;
    Node *next;
};

class Ans
{
public:
    Node *first = NULL;
    int ans = 0;
    Node *last = NULL;
    void add(int i)
    {
        if (i == ans)
        {
            if(first==NULL){ ans++; return;}
            while(true){
                if(first->next==NULL) break;
                if(first->next->num-first->num<=1){
                    if(first->next->num-first->num==1) ans++;
                    first = first->next;
                }else break;
            }
            ans++;
            if(first->num==ans){
                ans++;
                first=first->next;
            }
        }
        else
        {
            if (first == NULL) // first item
            { 
                first = new Node(i);
            }
            else
            {
                if (i == first->num || (last!=NULL && i == last->num) || i<ans) return;
                Node *temp = new Node(i);
                if(i<first->num){
                    temp->next = first;
                    if(last==NULL) last = first;
                    first = temp;
                    // ans->next = first;
                }else if(last==NULL){
                    last = temp;
                    first->next = last;
                }
                else if (i > last->num)
                {
                    last->next = temp;
                    last = temp;
                }
                else {
                    // insertion
                    Node *ite = first;
                    while (ite->next != last)
                    {
                        if (ite->next->num > i)
                            break;
                        ite = ite->next;
                    }
                    temp->next = ite->next;
                    ite->next = temp;
                }
            }
            
        }
        // show();
        // cout<<"DONE";
    }
    void show()
    {
        cout<<"ANS: "<<ans<<"\n";
        // cout<<"ANS->next: "<<ans->next->num<<"\n";
        if (first==NULL) return;
        Node *ite = first;
        cout << "SHOW:\n";
        while (true)
        {
            cout << ite->num<< " " ;
            if(last==NULL) return;
            if(ite==last) break;
            if(ite->next!=NULL)
            ite = ite->next;
        }
        cout<<"\n";
        
    }
};

int main()
{
    int n, in;
    // cout<<"N: ";
    while (cin >> n)
    {
        Ans *ans = new Ans();
        for (int i = 0; i < n; i++)
        {
            cin >> in;
            ans->add(in);
        }
        // ans->show();
        cout<<ans->ans<"\n";
        // cout<<"\nN: ";
    }
}