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

vector<int> adj[N];
bool vis[N];
int cost[N];
int n, m, minCost;

void dfs(int node){
    vis[node] = 1;
    minCost = min(minCost, cost[node]);
    for(int ch:adj[node]){
        if(!vis[ch]) dfs(ch);
    }
}

int main(){
    fastInputOutput();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=0;i<m;i++){
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll total = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            minCost = INT_MAX;
            dfs(i);
            total += minCost;
        }
    }
    cout<<total<<endl;
    return 0;
}
