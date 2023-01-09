// คิดไม่ออก คิดออกแต่อะไรที่มัน tedious af
#include<cstdio>

int lca(int a1, int b1, int a2,int b2){
    if((a1-b1)*(a2-b2)<0){
        printf("1 1");
    }else{
        if((a1-b1)>0){
            
        }
    }
}

int main(){
    int a1,b1,a2,b2;
    while(scanf("%d %d %d %d",&a1,&b1,&a2,&b2)){
        if((a1==b1)&&(b1==b2)&&(b2==a2)&&(a2==0)) break;
        lca(a1,b1,a2,b2);
    }
}