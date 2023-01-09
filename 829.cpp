#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

// int median(priority_queue <int, vector<int>, greater<int> >  pq, int n){
//     priority_queue <int, vector<int>, greater<int> > copy = pq;
//     for(int i=0;i<n/2;i++) copy.pop();
//     return copy.top();
// }

// int median(int* arr, int k){
//     //median of A[1...2*k-1] -> actually 0 to 2k
//     // for(int i=0;i<k;i++) cout<<arr[i]<<" ";
//     // cout<<"*\n";
//     if(k==1) return arr[1];
//     else if(k==3) return arr[2];
//     // cout<<k<<" "<<k/2<<" "<<1+(k/2)<<"\n";
//     // sort(arr,arr+k);
//     return (arr[k/2]+arr[1+(k/2)])/2;
    
// }

void currentstate(priority_queue <int> x){
    priority_queue <int> a = x;
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<"\n";
}

void currentstate(priority_queue <int, vector<int>, greater<int> > x){
    priority_queue <int, vector<int>, greater<int> > a = x;
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<"\n";
}

int main(){
    int n,a;
    while(cin>>n){
        int*arr = new int[n+1];
        priority_queue <int, vector<int>, greater<int> >  minn;
        priority_queue <int> maxx;
        for(int i=1;i<=n;i++){
            cin>>a;
            arr[i]=a;
        }
        int median = arr[1];
        minn.push(arr[1]);
        // cout<<minn.top()<<" ";
        // minn.push();
        for(int j = 2;j<=n;j+=2){
            if(maxx.empty() || minn.size()-maxx.size()==1) cout<<minn.top()<<"\n";
            else cout<<maxx.top()<<"\n";
            if(j==n){
                if(arr[j]<maxx.top())maxx.push(arr[j]);
                else minn.push(arr[j]);
                break;
            }
            
            if(!minn.empty()&&arr[j]>minn.top())minn.push(arr[j]);
            else maxx.push(arr[j]);
            if(!minn.empty()&&arr[j+1]>minn.top())minn.push(arr[j+1]);
            else maxx.push(arr[j+1]);
            int sizedif = maxx.size()-minn.size();
            // int count=0;
            // cout<<"\n-------\n";
            //     currentstate(minn);
            //     currentstate(maxx);

            while(abs(sizedif)>1){
                // minn.push(maxx.top()); maxx.pop();
                if(minn.size()>maxx.size()) {maxx.push(minn.top()); minn.pop();}
                else {minn.push(maxx.top()); maxx.pop();}
                // cout<<"\n*****\n";
                // currentstate(minn);
                // currentstate(maxx);
                sizedif = maxx.size()-minn.size();
                // count++;
            }
            
            // cout<<"======\n";
            // currentstate(minn);
            // currentstate(maxx);
            // cout<<"\n";


        }
        if(n%2==1)
        if(maxx.empty() || minn.size()-maxx.size()==1) cout<<minn.top()<<"\n";
        else cout<<maxx.top()<<"\n";
        // cout<<pq;
        // for(int i = 1;i<=n;i++) {arr[i]=pq.top(); pq.pop();}
        // int size = 1;
        // int medianind = 1;
        // pq.push(arr[size++]);
        // for(int j = 1;j<=n/2;j++){
        //     int max = arr[size];
        //     int min = arr[size+1];
        //     if(max<min){
        //         int temp = max;
        //         max = min;
        //         min = temp;
        //     }
        //     if(max>arr[medianind]) 
        //     // if(medianind==pq.top()) cout<<median;
        //     // if(medianind>pq.top())
        //     // cout<<median(pq)<<'\n';
        //     pq.push(arr[size++]);
        //     pq.push(arr[size++]);
        //     // cout<<median(pq,2*j-1)<<'\n';
        //     size+=2;
        // }
    }
}
// 1 3 5 6 7 9 11
// k=2 1 3 k = 3 1 3 5
// k=4 1 3 5 6 7
// k=5 1 3 5 6 7 9 11