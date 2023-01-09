#include<cstdio>

int main(){
    //increasing then decreasing list ; find the length
    int n,num,latest;
    scanf("%d",&n);
    int lende=1;
    int lenas = 1;
    scanf("%d",&latest);
    int equal =latest;
    int i=1;
    while(i<n){
        scanf("%d",&num);
        if(num>latest){
            lenas+=1;
        }
        if(num==latest){
            equal=num; 
            lende++;
            lenas++;
        }if(num!=equal && num<=latest){
            lende+=(n-i);
            break;
        }
        // if(num>=latest) {
        //     lende++;
        // }if(num<=latest){
        //     lenas++;
        // }
        latest = num;
        i++;
    }
    printf("%d %d\n",lenas,lende);
    return 0;
}