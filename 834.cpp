#include<iostream>
#include<cmath>
using namespace std;

class yangOrder{
    public:
    int *rank, *total, *gr;
    yangOrder(){
        rank = new int[30003];
        total = new int[30003];
        gr = new int[30003];
        for(int i=0;i<=30001;i++){
            gr[i]=i;
            total[i]=1;
        }
    }
    int find(int x)
    {
        if (x==gr[x]) return x;
        int temp = find(gr[x]);
        rank[x]+=rank[gr[x]];
        gr[x] = temp;
        return temp;
    }
    void gathering(int i, int j)
    {
        i = find(i);
        j = find(j);
        gr[i] = j;
        rank[i]+=total[j];
        total[j]+=total[i];
    }
    int reinhard(int i,int j){
        if (find(i)!=find(j)) return -1;
        return abs(rank[j]-rank[i]);
    }
};

int main()
{
    int i,j,t; 
    cin>>t;
    char c; 
    yangOrder* ans = new yangOrder();
    while(t--)
    {
        cin>>c>>i>>j;
        if (c=='M') ans->gathering(i,j);
        else cout<<ans->reinhard(i,j)<<"\n";   
    }
}