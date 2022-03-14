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

const int N = 1e3+9;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

char grid[N][N];
int dp[N][N][3];
int dots[M];
int n, m, x, y;

int minChanges(int col, int seqLen, int last){
    if(col == m){
        if(seqLen > y || seqLen < x) return OO;
        return 0;
    }
    int& ans = dp[col][seqLen][last];
    if(ans != -1) return ans;
    int opDots = OO, opHashes = OO;
    if(col == 0 || (last == 0 && seqLen+1 <= y) || (last == 1 && seqLen >= x)){
        opDots = n-dots[col]+minChanges(col+1, (last == 0) ? seqLen+1:1, 0);
    }
    if(col == 0 || (last == 1 && seqLen+1 <= y) || (last == 0 && seqLen >= x)){
        opHashes = dots[col]+minChanges(col+1, (last == 1) ? seqLen+1:1, 1);
    }
    return ans = min(opDots, opHashes);
}


int main(){
    FIO();
    memset(dp, -1, sizeof dp);
    cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == '.') dots[j]++;
        }
    }
    cout<<minChanges(0, 0, 2);
    return 0;
}
