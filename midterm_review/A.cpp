#include<iostream>
using namespace std;

bool fight(int hpM,int pntM,int hpD,int pntD,int res){
    while(true){
        hpD-=pntM;
        if(hpD<=0) return true;
        hpM-=pntD;
        if(hpM<=0) return false;
        hpD+=res;
        // cout<<hpM<<pntM<<hpD<<pntD<<res<<"\n";
    }
}
// HP and attack point of Mira, HP, attack point and restoration per turn of the drago
int main(){
    while(true){
        int hpM, pntM, hpD, pntD, resD;
        cin>>hpM>>hpD>>pntM>>pntD>>resD;
        if(fight(hpM, pntM, hpD, pntD, resD)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}