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

const int N = 3005;
int prime[N];

void sieve(){
    /// 1 -> not prime, 0 -> prime
    prime[0] = prime[1] = 1;
    for(int i=2;i*i<N;i++){
        if(prime[i] == 0){
            for(int j=i*i;j<N;j+=i){
                prime[j] = 1;
            }
        }
    }
}

int primeDivs[N];

void fillPrimeDivs(){
    for(int i=0;i<N;i++){
        if(prime[i] == 0){
            for(int j=2*i;j<N;j+=i){
                primeDivs[j]++;
            }
        }
    }
}

int main(){

    fastInputOutput();
    sieve();
    fillPrimeDivs();
    int n, ans=0;cin>>n;
    for(int i=1;i<=n;i++){
        ans+=(primeDivs[i] == 2);
    }
    cout<<ans<<endl;

    return 0;
}
