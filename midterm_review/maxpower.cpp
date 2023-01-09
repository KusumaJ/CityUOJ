#include<cstdio>

int find(int n,int ope){
    // printf("%d\n",((n/ope)%10)*(ope/10)+(n%ope));
    printf("ope:%d n:%d\n",ope,n);
    if(ope==1) return n/10;
    if(n/ope<=10){
        while(n>ope) n-=ope;
        return n;
    }
    // 1011/10 = 101 
    printf("whyyy?: %d %d %d\n",n/(10*ope),(n/(10*ope))*10,(n/(10*ope))*10+n%ope);
    return ((n/(10*ope))*10 +n%ope);
    // *(ope/10)+(
}

int main(){
    int t,n,k;
    // printf("%d",1011/10);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        // int smallest = 0;
        scanf("%d %d",&n,&k);
        int smallesthere = n;
        for(int j=1;j<=k;j++){
            int ope = 1;
            while(ope<=n){
                printf("ope: %d n: %d smallest: %d\n",ope,n,smallesthere);
                printf("%d\n",find(n,ope));
                if(find(n,ope)<smallesthere) smallesthere = find(n,ope);
                ope*=10;
            }
            n = smallesthere;
        }
        printf("%d\n",n);
    }
    return 0;
}