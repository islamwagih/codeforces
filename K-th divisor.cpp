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
vector<ll> toFil;
void fillDivisors(ll n){
    for(ll i=1;i*i<=n;i++){
        if(n%i == 0){
            toFil.push_back(i);
            if(i*i != n)toFil.push_back(n/i);
        }
    }
    sort(toFil.begin(), toFil.end());
}

int main(){
    fastInputOutput();
    ll n, k;cin>>n>>k;
    fillDivisors(n);
    if(toFil.size() < k){
        cout<<-1<<endl;
    }else{
        cout<<toFil[k-1]<<endl;
    }
    return 0;
}
