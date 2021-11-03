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

const int N = 2e5+5;
const int inf = 2e9+1;

vector<int> adj[N];
int col[N];

void dfs(int node, int par){
    int c = 1;
    for(int ch:adj[node]){
        if(ch == par) continue;
        while(c == col[node] || c == col[par]) c++;
        col[ch] = c++;
        dfs(ch, node);
    }
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    col[1] = 1;
    dfs(1, 1);
    int mx = -1;
    for(int i=1;i<=n;i++) mx = max(mx, col[i]);
    cout<<mx<<endl;
    for(int i=1;i<=n;i++) cout<<col[i]<<' ';

    return 0;
}
