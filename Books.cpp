#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n, t;cin>>n>>t;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int p1 = 0, p2 = 0, length = 0, sum = 0, maxLength = 0;
    while(p1 < n){
        if(sum < t && p2 < n &&(arr[p2] + sum) <= t){
            sum += arr[p2];
            length++;
            p2++;
        }else{
            maxLength = max(length, maxLength);
            sum -= arr[p1];
            length--, p1++;
        }
    }
    cout<<maxLength<<endl;
    return 0;
}
