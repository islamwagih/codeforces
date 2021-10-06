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

const int N = 1e6;
bool vis[N];
int out[N];
vector<int> graph[N];
bool goodComp = 1;
void dfs(int node){
    vis[node] = 1;
    if(out[node] != 2) goodComp = 0;
    for(int child:graph[node]){
        if(!vis[child]) dfs(child);
    }
}



int main(){

    fastInputOutput();
    int n,m;cin>>n>>m;
    while(m--){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        out[u]++, out[v]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            goodComp = 1;
            dfs(i);
            if(goodComp) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;

}
