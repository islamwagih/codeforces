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

const int N = 1e7 + 7;
int arr[N];
int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, k;cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>arr[i];
        ll ans = -1e18;
        for(int i=max(1, n-205);i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans = max(ans, 1ll*i*j - 1ll*k*(arr[i]|arr[j]));
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
