#include<iostream>
using namespace std;
//Suppose you have declared two int arrays A[] and B[]

const int MAXSIZE = 10000000 + 5;
int n, m, A[MAXSIZE], B[MAXSIZE];

//copy the method below into your program:

void generateArray(int* A, int* B, int n, int m, unsigned seed) {
    unsigned x = seed;
    A[1] = 0;
    for (int i = 2; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        A[i] = A[i - 1] + x % 100;
    }
    B[1] = 0;
    for (int i = 2; i <= m; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        B[i] = B[i - 1] + x % 100;
    }
}
//and call it in main() as below to acquire and store the generated numbers into two int arrays with name "A" and "B"

int main() {
    unsigned seed;
    cin >> n >> m >> seed;
    generateArray(A, B, n, m, seed);
    //The arrays mentioned above are now stored in array "A" and "B" respectively, please continue here to solve the problem.
    int indexA=1,indexB=1;
    unsigned long long int count=0;
    while(indexA<=n){
        // cout<<A[indexA]<<" "<<B[indexB]<<"\n";
        if(indexB>m) break;
        if(A[indexA]>=B[indexB]){ 
            indexB++;
        }
        else{ 
            count+=(m-indexB+1);
            // indexB=1;
            indexA++;
        }
        
    }
    cout<<count;

}