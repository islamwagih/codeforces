#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 1e6+5;
int a, b, n;

int fact[N];

int add(int a, int b){
    return (((1ll*a)%mod)+(b%mod))%mod;
}

int mul(int a, int b){
    return (((1ll*a)%mod)*(b%mod))%mod;
}

void buildFact(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = mul(fact[i-1], i);
    }
}

int binExp(int base, int p){
    int ans = 1;
    while(p){
        if(p & 1) ans = mul(ans, base);
        base = mul(base, base);
        p>>=1;
    }
    return ans;
}

int inv(int x){
    return binExp(x, mod-2);
}

bool ok(ll num){
    while(num){
        int last = num%10;
        if(last != a && last != b) return false;
        num/=10;
    }
    return true;
}

ll nCr(int n, int r){
    return mul(mul(fact[n], inv(fact[r])), inv(fact[n-r]));
}

int main(){

    fastInputOutput();
    buildFact();
    cin>>a>>b>>n;
    ll ans = 0;
    for(int alen=0;alen<=n;alen++){
        int blen = n-alen;
        ll sum = 1ll*alen*a + blen*b;
        if(ok(sum)) ans = add(ans, nCr(n, alen));
    }
    cout<<ans<<endl;
    return 0;
}
