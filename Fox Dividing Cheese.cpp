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

const int N = 5e3+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;

map<pair<ll, ll>, ll> dp;
ll ops(ll a, ll b){
    if(a == b) return 0;
    if(a < b) swap(a, b);
    if(dp.find({a, b}) != dp.end()) return dp[{a, b}];
    ll op1 = inf, op2 = inf, op3 = inf;
    if(a%2 == 0){
        ll newA = a/2;
        op1 = 1+ops(newA, b);
    }
    if(a%3 == 0){
        ll newA = a-((2*a)/3);
        op2 = 1+ops(newA, b);
    }
    if(a%5 == 0){
        ll newA = a-((4*a)/5);
        op3 = 1+ops(newA, b);
    }
    return dp[{a, b}] = min({op1, op2, op3});
}

int main(){
    fastInputOutput();
    ll a, b;cin>>a>>b;
    ll ans = ops(a, b);
    cout<<(ans == inf ? -1: ans)<<endl;
    return 0;
}
