#include<iostream>

using namespace std;


class stack{
    private:
    int arr[3000];
    
    public: 
    int top = -1;
    void addElement(int ele){
        // cout<<"addaddadd"<<ele<<"\n";
        top++;
        arr[top] = ele;
    }
    int getTop(){ if (top>=0) return arr[top]; else return top;}
    // void showElement(){
    //     for (int i=0;i<top+1;i++){
    //         cout<<arr[i]<<" ";
    //     }cout<<"\n";
    // }
    int getInd(int i){ return arr[i];}
    int pop(){
        // cout<<"popopopop"<<arr[top]<<"\n";
        top--;
        return arr[top+1];
    }
    void clear() {top=-1;}
};

int main(){
    int T;
    cin>>T;
    int n,m;
    for(int t=0;t<T;t++){  
        cin>>n;
        stack* ARef = new stack;
        stack* B = new stack;
        stack* S = new stack;
        stack* A = new stack;
        int num;
        for(int nn=0;nn<n;nn++){
        // get A
            cin>>num;
            ARef->addElement(num);
        }
        // for(int nn=0;nn<n;nn++) A->showElement();
        cin>>m;
        for(int mm=0;mm<m;mm++){
            for(int nn=0;nn<n;nn++){
                // copy aref to a
                A->addElement(ARef->getInd(nn));
                //input b
                cin>>num;
                B->addElement(num);
            }
            int bindex = 0;
            // cout<<"checkingggg\n";
            while(true){
                // A->showElement();
                // B->showElement();
                // S->showElement();
                // cout<<"================\n";
                
                // cout<<A->pop();
                S->addElement(A->pop());

                while(B->getTop()>=0 && B->getInd(bindex)==S->getTop()){
                    B->pop();
                    S->pop();
                    bindex++;
                }
                
                if(A->getTop()<0) {
                    if(bindex==n) {cout<<"Aye\n"; break;}
                    cout<<"Impossible\n";
                    break;
                }
                
                // S->showElement();
                // cout<<" "<<A->top<<" "<<B->top<<" "<<S->top;
                // cout<<"\n@@@@@@@@\n";   
                // counter++;
            }

            A->clear();
            B->clear();
            S->clear();
        }
    }
    return 0;
}