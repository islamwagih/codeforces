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
const int N = 1e7+1;

ll f[N], cnt[N], isComp[N];
void sieve(){
    isComp[0] = isComp[1] = 1;
    for(ll i=2;i<N;i++){
        if(!isComp[i]){
            for(ll j=i*2;j<N;j+=i){
                if(cnt[j]) f[i]+=cnt[j];
                isComp[j] = 1;
            }
            f[i]+=cnt[i];
        }
    }
}

void cumSum(){
    for(int i=1;i<N;i++) f[i]+=f[i-1];
}

int main(){

    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        cnt[val]++;
    }
    sieve();
    cumSum();
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        int up = 1e7;
        if(l > up){cout<<0<<endl; continue;}
        if(r > up) r = up;
        cout<<f[r]-f[l-1]<<endl;
    }
    return 0;
}
