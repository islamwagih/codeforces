#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5+2;
const int inf = 2e9+1;
const int M = 2*N;

int par[N];
pair<int, int> cap[N];

void init(){
    iota(par, par+N, 0);
}

int getPar(int u){
    if(u == par[u]) return u;
    return par[u] = getPar(par[u]);
}

void join(int u, int v){
    u = getPar(u), v = getPar(v);
    if(u != v){
        if(cap[u].S-cap[u].F < cap[v].S-cap[v].F) swap(u, v);
        par[v] = u;
    }
}

int main(){
    fastInputOutput();
    init();
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>cap[i].S;
    int q;cin>>q;
    while(q--){
        int type, pi;cin>>type>>pi;
        pi--;
        if(type == 1){
            int xi;cin>>xi;
            int oldPi = -1;
            while(oldPi != pi && xi > 0){
                int toFill = cap[pi].S-cap[pi].F;
                if(xi <= toFill){
                    cap[pi].F += xi;
                    xi -= xi;
                }else{
                    ///it will fill and there will be a remaining
                    xi -= toFill;
                    cap[pi].F += toFill;
                    ///join pi to pi+1 if and only if pi <= n-2;
                    if(pi <= n-2) join(pi+1, pi);
                    ///repeat the process with the par
                    oldPi = pi;
                    pi = getPar(pi);

                }
            }
        }else{
            cout<<cap[pi].F<<endl;
        }
    }
    return 0;
}
