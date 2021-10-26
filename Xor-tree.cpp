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

const int N = 1e5+5;
const int inf = 2e9+1;

vector<int> adj[N], flipped;
bool vis[N], init[N], goal[N];

int dfs(int node, bool d, bool o, bool e){
    vis[node] = 1;
    int ret = 0;
    if((d && o)|| (!d && e)) init[node]^=1;
    if(init[node] != goal[node]){
        ret++;
        init[node]^=1;
        if(d) o ^= 1;
        else e ^= 1;
        flipped.push_back(node);
    }
    for(int ch:adj[node]){
        if(!vis[ch]){
            ret += dfs(ch, d^1, o, e);
        }
    }
    return ret;
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>init[i];
    for(int i=1;i<=n;i++) cin>>goal[i];
    cout<<dfs(1, 0, 0, 0)<<endl;
    for(int node:flipped) cout<<node<<endl;
    return 0;
}
