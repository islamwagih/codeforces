#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int n, m, a, b;
int dp[(int)1e4];
int solve(int r){
    if(r <= 0){
        return 0;
    }
    if(dp[r]) return dp[r];
    int ans1 = a+solve(r-1);
    int ans2 = b+solve(r-m);
    dp[r] = min(ans1, ans2);
    return dp[r];
}

int main(){

    fastInputOutput();
    cin>>n>>m>>a>>b;
    cout<<solve(n)<<endl;
    return 0;

}
