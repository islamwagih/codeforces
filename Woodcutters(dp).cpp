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

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5+9;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> x, h;
int dp[N][5];

int maxTrees(int i, bool lstRightFell){
    if(i == n) return 0;
    if(dp[i][lstRightFell] != -1) return dp[i][lstRightFell];
    int op1 = (i == n-1 || x[i]+h[i] < x[i+1]) ? 1+maxTrees(i+1, 1):0;
    int op2 = (i == 0 || (lstRightFell && x[i]-h[i] > x[i-1]+h[i-1]) || (!lstRightFell && x[i]-h[i] > x[i-1])) ? 1+maxTrees(i+1, 0):0;
    return dp[i][lstRightFell] = max(maxTrees(i+1, 0), max(op1, op2));
}

int main(){
    FIO();
    memset(dp, -1, sizeof dp);
    cin>>n;
    x.resize(n);
    h.resize(n);
    for(int i=0;i<n;i++) cin>>x[i]>>h[i];
    cout<<maxTrees(0, 0)<<endl;
    return 0;
}
