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

void dfs(int node){
    vis[node] = 1;
    for(int ch:adj[node]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    for(int u=1;u<=n;u++){
        int v;cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ccCount = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i), ccCount++;
    }
    cout<<ccCount<<endl;
    return 0;
}
