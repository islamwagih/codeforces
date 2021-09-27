#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 5;

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    if(a < b) swap(a, b);
    return a*b/gcd(a, b);
}

int main(){
    fastInputOutput();
    ll x, a, b;cin>>x;
    a = 1, b = x;
    for(ll i=1;i*i<x;i++){
        if(x%i == 0){
            if(lcm(x/i, i) == x && max(x/i,i) < b){
                a = min(i, x/i);
                b = max(i, x/i);
            }
        }
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}
