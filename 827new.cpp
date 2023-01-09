#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
int score(int*arr,int n){
    priority_queue <int, vector<int>, greater<int> >  pq;
    for(int i=1;i<=n;i++) pq.push(arr[i]);
    while (pq.size() >1)
    {
        // cout << pq.top() << " ";
        pq.push(pq.top()*2);
        pq.pop();
        pq.pop();
    }
    return pq.top();
}

int main(){
    int n,m,seed;
    cin>>n>>m>>seed;
    int* arr = new int[n];
    //and call it in main() as below to acquire and store the generated numbers
    generateArray(arr, n, m, seed);
    cout<<score(arr,n)<<'\n';
}