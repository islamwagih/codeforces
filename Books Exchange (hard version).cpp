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

const int N = 2e5+5;
const int inf = 2e9+1;

int par[N], cnt[N];

void init(){
    iota(par, par+N, 0);
    fill(cnt, cnt+N, 1);
}

int findPar(int u){
    if(u == par[u]) return u;
    return par[u] = findPar(par[u]);
}

void join(int u, int v){
    u = findPar(u), v = findPar(v);
    if(u != v){
        if(cnt[u] < cnt[v]) swap(u, v);
        par[v] = u;
        cnt[u] += cnt[v];
    }
}

int main(){
    fastInputOutput();
    int q;cin>>q;
    while(q--){
        int n;cin>>n;
        iota(par, par+n, 0);
        fill(cnt, cnt+n, 1);
        for(int v=0;v<n;v++){
            int u;cin>>u;
            join(v, --u);
        }
        for(int i=0;i<n;i++) cout<<cnt[findPar(i)]<<' ';
        cout<<endl;
    }
    return 0;
}
