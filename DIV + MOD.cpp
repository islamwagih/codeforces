#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;

ll f(ll x, ll a){
    return (x/a) + (x%a);
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        ll l, r, a;
        cin>>l>>r>>a;
        ll ans = f(r, a);
        r-=(r%a)+1;
        if(r >= l) ans = max(ans, f(r, a));
        cout<<ans<<endl;
    }
    return 0;
}
