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

const int N = 1e2+9;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;

int arr[N];
int dp[N][N];
int n;
int solve(int i, int lst){
    if(i == n) return 0;
    int& ans = dp[i][lst];
    if(ans != OO) return ans;
    if(arr[i] == 3){
        if(lst == 1){
            ans = min(ans, solve(i+1, 0));
        }else if(lst == 0){
            ans = min(ans, solve(i+1, 1));
        }else{
            ans = min(solve(i+1, 1), solve(i+1, 0));
        }
    }else if(arr[i] == 2){
        if(lst == 1 || lst == 2) ans = min(ans, solve(i+1, 0));
        else ans = 1+solve(i+1, 2);
    }else if(arr[i] == 1){
        if(lst == 0 || lst == 2) ans = min(ans, solve(i+1, 1));
        else ans = 1+solve(i+1, 2);
    }else{
        ans = 1+solve(i+1, 2);
    }
    return ans;
}

int main(){
    fastInputOutput();
    memset(dp, OO, sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(0, 2)<<endl;
    return 0;
}
