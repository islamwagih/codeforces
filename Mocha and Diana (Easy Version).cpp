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

const int N = 1e3+5;
const int inf = 2e9+1;

class Dsu{
    private:
        int* par, *cnt, n, m;
    public:
        Dsu(int n, int m) : n(n), m(m){
            par = new int[n+5];
            cnt = new int[n+5];
            iota(par, par+n, 0);
            fill(cnt, cnt+n, 1);
        }
        int findPar(int u){
            if(u == par[u]) return u;
            return par[u] = findPar(par[u]);
        }
        bool canBeJoined(int u, int v){
            u = findPar(u), v = findPar(v);
            if(u == v) return false;
            return true;
        }
        void join(int u, int v){
            u = findPar(u), v = findPar(v);
            if(u != v){
                if(cnt[u] < cnt[v]) swap(u, v);
                par[v] = u;
                cnt[u] += cnt[v];
            }
        }
        ~Dsu(){
            delete[] par;
            delete[] cnt;
        }
};


int main(){
    fastInputOutput();
    int n,m1,m2;
    cin>>n>>m1>>m2;
    Dsu mocha(n, m1), diana(n, m2);
    for(int i=0;i<m1;i++){
        int u, v;cin>>u>>v;
        u--, v--;
        mocha.join(u, v);
    }
    for(int i=0;i<m2;i++){
        int u, v;cin>>u>>v;
        u--, v--;
        diana.join(u, v);
    }
    vector<pair<int, int>> edges;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(mocha.canBeJoined(i, k) && diana.canBeJoined(i, k)){
                edges.push_back(make_pair(i, k));
                mocha.join(i, k);
                diana.join(i, k);
            }
        }
    }
    cout<<edges.size()<<endl;
    for(auto& edge:edges){
        cout<<edge.F+1<<' '<<edge.S+1<<endl;
    }
    return 0;
}
