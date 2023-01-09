#include<cstdio>
// using namespace std;

int main(){
    int t,n,num;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        int *arr = new int[n];
        int index = 0;
        int count=0;
        for(int j=0;j<n;j++){
            scanf("%d",&num);
            arr[index++]=num;
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++){
                if(arr[i]-arr[j]==i-j)count+=1;
            }
        }
        printf("%d\n",count);
    }
}