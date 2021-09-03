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

const int N = (1e6)+5;
bool prime[N];
void Sieve(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p < N; p++){
        if (prime[p] == 1){
            for (int i = p * p; i < N; i += p)
                prime[i] = 0;
        }
    }
}

int main(){

    fastInputOutput();
    Sieve();
    int n;cin>>n;
    while(n--){
        ll x;cin>>x;
        ll sqrtx = sqrt(x);
        if(sqrtx*sqrtx == x){
            cout<<(prime[sqrtx] == 1 ? "YES":"NO")<<endl;
        }else{
            cout<<"NO\n";
        }
    }

    return 0;

}