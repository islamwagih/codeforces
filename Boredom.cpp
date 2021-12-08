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

const int N = 1e5+5;
const int inf = 1e5+5;
const int M = 2*N;

int frq[N];
int n;
int lowerBound = INT_MAX, upperBound = INT_MIN;

ll dp[N];
ll solve(ll val){
    if(val > upperBound) return 0;
    if(dp[val] != -1) return dp[val];
    ll op1 = frq[val]*val+solve(val+2);
    ll op2 = solve(val+1);
    return dp[val] = max(op1, op2);
}

int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        frq[x]++;
        lowerBound = min(lowerBound, x);
        upperBound = max(upperBound, x);
    }
    cout<<solve(lowerBound)<<endl;

    return 0;
}
