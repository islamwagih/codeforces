#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
//multi indexedSet -> less_equal<int>/greater_equal<int>
//indexedSet -> less<int>/greater<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
*/

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 2e2+5;
const int inf = 1e9;

ll add(ll a, ll b){
    return ((a%mod)+(b%mod))%mod;
}

ll sub(ll a, ll b){
    return ((a%mod)-(b%mod)+mod)%mod;
}

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll binExp(ll b, ll p){
    ll ans = 1;
    while(p){
        if(p & 1) ans = mul(ans, b);
        b = mul(b, b);
        p>>=1;
    }
    return ans;
}

int main(){

    fastInputOutput();

    int n;cin>>n;
    ll ans = sub(binExp(3, 3*n), binExp(7, n));
    cout<<ans<<endl;

    return 0;
}
