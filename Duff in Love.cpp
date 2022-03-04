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

vector<ll> divisors(ll x){
    vector<ll> divs;
    for(ll i=2;i*i<=x;i++){
       if(x%i == 0){
            divs.push_back(i);
            if(i*i != x) divs.push_back(x/i);
       }
    }
    divs.push_back(x);
    return divs;
}

bool lovely(ll x){
    for(ll i=2;i*i<=x;i++){
        if(x%(i*i) == 0) return false;
    }
    return true;
}

int main(){
    fastInputOutput();
    ll a;cin>>a;
    vector<ll> nums = divisors(a);
    sort(nums.rbegin(), nums.rend());
    for(ll num:nums){
        if(lovely(num)){
            cout<<num<<endl;
            break;
        }
    }
    return 0;
}
