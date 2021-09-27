#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e7;
int arr[N];
int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll ans = 0, mn = INT_MAX, mx = INT_MIN;
        for(int i=1;i<n;i++){
            mx = max(arr[i], arr[i-1]);
            mn = min(arr[i], arr[i-1]);
            ans = max(ans, mx*mn);

        }
        cout<<ans<<endl;
    }

    return 0;
}
