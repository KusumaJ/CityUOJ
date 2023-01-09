#include <iostream>
using namespace std;
class linkedList{
    public:
        int data;
        linkedList *next;
};

class Queue
{
    private:
        linkedList *front = new linkedList;
        linkedList *rear = new linkedList;
        int maxsize;
        int amount = 0;

    public:
        Queue(int n){maxsize = n;};
        bool checkEle(int n)
        {
            if(amount==0) {return false;}
            if(amount==1) {return front->data==n;}
            linkedList *check = front;
            while (check->next != front)
            {
                if (check->data == n)
                    return true;
                check = check->next;
            }
            return (check->data == n); //is the number == last element?
        }
        void appendEle(int n)
        {
            if(maxsize==1){
                front->data=n;
                front->next=rear;
                rear=front;
                amount=1;
            }
            if (amount == 0)
            {
                front->data = n;
                front->next = rear;
                rear = front;
                amount++;
            }
            else if (amount==maxsize)
            {
                linkedList *temp = new linkedList;
                front = front->next;
                rear->next = temp;
                temp->data = n;
                rear = temp;
                rear->next = front;
            }
            else
            {
                linkedList *temp = new linkedList;
                temp->data = n;
                rear->next = temp;
                rear = temp;
                rear->next = front;
                amount++;
            }
        }
        void showEle()
        {
            if(amount>0){
                linkedList *check = front;
                while (check->next != front)
                {
                    cout << "*" << check->data << "* ";
                    check = check->next;
                }
                cout << "*" << check->data << "* ";
            }
        }
};

int main()
{
    // m storage units for internal
    // n words essay
    // how many times the translator use external dict
    // initially got no word
    int n, m;
    int num;
    int count = 0;
    cin >> m >> n;

    Queue *dict = new Queue(m);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> num;
    while(cin>>num){
        // if not in the dict
        if (!dict->checkEle(num))
        {
            count += 1;
            // add to the dict
            dict->appendEle(num);
            // dict->showEle();
        }
        // else {cout<<num<<" ";}

        // dict->showEle();
        n--;
        if(n==0) break;
    }

    cout <<count<<"\n";
    return 0;
}