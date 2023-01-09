#include<cstdio>
#include<iostream>
using namespace std;
class City{
    public:
    int *arr;
    int index=0;
    unsigned long long int cost=0;
    City(int n){arr = new int[n];}
    void append(int num){
        arr[index++]=num;
    }
    int getCost(){
        cost = arr[0]-arr[index-1];
        if(cost<0) cost*=(index*-1);
        else cost*=index;
        // )*index;
        int val;
        for(int i=0;i<index;i++){
            unsigned long long int bestcost = 0;
            // printf("%d\n",arr[i]);
            for(int j=0;j<index;j++) {
                // printf("%d %d %d\n",arr[i],arr[j],bestcost);
                val = arr[i]-arr[j];
                if(val<0) val*=-1;;
                bestcost+=val;
            }
            // printf("%d\n",bestcost);
            if(bestcost<cost){ 
                //believe that the bestcost should be earned by those not in the edge
                cost = bestcost;
            }else{
                break;
            }
            // if(bestcost>cost);
        }
        return cost;
    }
};



int main(){
    int n;
    int num;
    scanf("%d",&n);
    City *city = new City(n);
    //descending or ascending
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        city->append(num);
    }
    cout<<city->getCost();
    return 0;
}