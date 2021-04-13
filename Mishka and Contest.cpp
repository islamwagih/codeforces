#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total = 0, stop = n-1;
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            total++;
        }else{
            stop = i;
            break;
        }
    }
    for(int i=n-1;i>stop;i--){
        if(arr[i] <= k){
            total++;
        }else{
            break;
        }
    }
    cout<<total<<endl;
    return 0;
}
