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
    int n,t;cin>>n>>t;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lp = 0, rp = 0, cnt = 0, maximum = 0;
    while(lp < n){
        if(rp < n && arr[rp] <= t){
            t -= arr[rp];
            cnt++;
            rp++;
        }else{
            cnt--;
            t += arr[lp];
            lp++;
        }
        maximum = max(cnt, maximum);
    }
    cout<<maximum<<endl;
    return 0;
}

