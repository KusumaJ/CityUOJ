#include<cstdio>
// using namespace std;


class trail{
    public:
    int *arr;
    int index=0;
    trail(int n){ arr = new int[n];}
    void append(int n){
        // printf("YEAA\n");
        arr[index++]=n;
    }
    void accident(int j,int k){
        arr[j]-=k;
        if(arr[j]<0) arr[j]=0;
        int count=1;
        int latest = arr[0];
        // printf("%d: %d\n",0,arr[0]);
        for(int i=1;i<index;i++){
            // printf("%d: %d\n",i,arr[i]);
            if(arr[i]<latest){
                count++;
                latest = arr[i];
            }
        }
        printf("%d\n",count);
    }
};

int main(){
    int num;
    int n,m;
    scanf("%d %d",&n,&m);
    trail* ans = new trail(n);
    // n carriage (1 to n numbered) spped up to ai less than a(i-1) 
    for(int i=0;i<n;i++){
        // initial speed
        scanf("%d",&num);
        ans->append(num);
    }
    
    for(int i=0;i<m;i++){
        int j,k;
        scanf("%d %d",&j,&k);
        ans->accident(j-1,k);
    }
}