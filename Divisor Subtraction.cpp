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

bool isPrime(ll n){
    if(n == 2) return true;
    if(n < 2 || n%2 == 0) return false;
    for(ll i=3;i*i<=n;i+=2) if(n%i == 0) return false;
    return true;
}

ll firstPrime(ll n){
    for(ll i=3;i<n;i+=2){
        if(isPrime(i) && n%i == 0){
                return i;
        }
    }
}

int main(){

    fastInputOutput();

    ll n;cin>>n;
    if(n%2 == 0) n/=2;
    else if(isPrime(n)) n = 1;
    else n = (n-firstPrime(n))/2 + 1;
    cout<<n<<endl;

    return 0;
}
