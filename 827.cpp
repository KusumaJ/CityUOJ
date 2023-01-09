#include<iostream>
#include<algorithm>
using namespace std;

//copy the method below into your program:
void generateArray(int* arr, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 1; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1;
    }
}

int score(int* arr, int n){
    int score = 0;
    int i =1;
    while(i<n){
        //1,2 to n-2,n-1
        if(arr[i]<arr[i+1]) arr[i+1]=arr[i];
        arr[i+1]*=2;
        sort(arr+i+1,arr+n+1);
        i++;
    }
    return arr[i];
}

int main(){
    int n,m,seed;
    cin>>n>>m>>seed;
    int* arr = new int[n];
    //and call it in main() as below to acquire and store the generated numbers
    generateArray(arr, n, m, seed);
    sort(arr+1,arr+n+1);
    // vector<int> v(arr+1,arr+n+1);
    // delete arr;
    // sort(v.begin(),v.end());
    // cout<<"\n";
    // for(int n:v) cout<<n<<" ";
    cout<<score(arr,n);
}