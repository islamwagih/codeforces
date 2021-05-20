#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    int sum = 0, ways = 0;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int partialSum = 0;
    for(int i=0;i<n-1;i++){
        partialSum += arr[i];
        if(partialSum == sum-partialSum){
            ways++;
        }
    }
    cout<<ways<<endl;
    delete[] arr;
    return 0;
}
