#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
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

const int N = 250009;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int n, k;
ll cost[N];
ll dp[N][10][10][3];

ll solve(int i,int x, int y, int s){
    if(i == n){
        return (s != 2 && x == y) ? 0:OOLL;
    }
    ll& ret = dp[i][x][y][s];
    if(~ret) return ret;
    ret = cost[i]+solve(i+1, x, y, 0);
    if(s < 2) ret = min(ret, solve(i+1, x, y, s+1));
    if(x > 0) ret = min(ret, solve(i+1, x-1, y, 0));
    if(y > 0 && s < 2) ret = min(ret, cost[i]+solve(i+1, x, y-1, s+1));
    return ret;
}


ll dpIter(){
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            for(int s=0;s<=2;s++){
                dp[n][x][y][s] = (s != 2 && x == y) ? 0:OOLL;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int x=0;x<=k;x++){
            for(int y=0;y<=k;y++){
                for(int s=0;s<=2;s++){
                    ll& ret = dp[i][x][y][s];
                    ret = cost[i]+dp[i+1][x][y][0];
                    if(s < 2) ret = min(ret, dp[i+1][x][y][s+1]);
                    if(x > 0) ret = min(ret, dp[i+1][x-1][y][0]);
                    if(y > 0 && s < 2) ret = min(ret, cost[i]+dp[i+1][x][y-1][s+1]);
                }
            }
        }
    }
    return dp[0][k][k][1];
}

int main(){
    FIO();
    memset(dp, -1, sizeof dp);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>cost[i];
    /*
    ll ans = OOLL;
    for(int g=0;g<=k;g++) ans = min(solve(0, g, g, 1), ans);
    cout<<ans<<endl;
    */
    cout<<dpIter()<<endl;
    return 0;
}
