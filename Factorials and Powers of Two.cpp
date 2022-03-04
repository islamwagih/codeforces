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

ll factDp[15];
ll fact(ll x){
    if(x <= 1) return 1;
    if(factDp[x] != -1) return factDp[x];
    return factDp[x] = x*fact(x-1);
}


int setBits(ll x){
    int cnt = 0;
    while(x){
        if(x&1) cnt++;
        x>>=1;
    }
    return cnt;
}

int main(){
    fastInputOutput();
    memset(factDp, -1, sizeof factDp);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        int ans = inf;
        for(int mask=0;mask<(1<<15);mask++){
            ll sum = 0;
            int cnt = 0;
            for(int i=0;i<15;i++){
                if(mask & (1<<i)){
                    //Calc ith factorial
                    sum += fact(i);
                    if(sum > n) break;
                    cnt++;
                }
            }
            if(sum <= n){
                ll rem = n-sum;
                ans = min(ans, cnt+setBits(rem));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
