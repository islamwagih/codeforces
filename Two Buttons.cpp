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

const int N = (1e4)+5;
int n, m;
bool visited[N];
int dp[N];

int solve(int x){
    if(x >= m){
        return x-m;
    }
    if(dp[x]) return dp[x];
    if(!visited[x]){
        visited[x] = 1;
        int first = 1+solve(x*2);
        dp[x] = (x-1 > 0) ? min(first, 1+solve(x-1)):first;
        visited[x] = 0;
        return dp[x];
    }
    return 1e3;
}

int main(){

    fastInputOutput();

    cin>>n>>m;
    cout<<solve(n)<<endl;

    return 0;
}
