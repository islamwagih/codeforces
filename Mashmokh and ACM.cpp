#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;
ll dp[N][N];
int n,k;

ll solve(ll i, int len){
    if(i > n) return 0;
    if(len == k) return 1;
    if(dp[i][len] != -1) return dp[i][len];
    ll ret = 0;
    for(int mul=1;mul*i<=n;mul++) ret = (ret%mod+solve(mul*i, len+1)%mod)%mod;
    return dp[i][len] = ret;
}



int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    cin>>n>>k;
    cout<<solve(1, 0)<<endl;
    return 0;
}
