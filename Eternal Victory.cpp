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

vector<pair<int, int>> adj[N];
bool vis[N];

int dfs(int node, int weight){
    vis[node] = 1;
    int ans = weight;
    for(pair<int, int> pr:adj[node]){
        if(!vis[pr.first]){
            ans = max(ans, dfs(pr.first, weight+pr.second));
        }
    }
    return ans;
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    ll minSum = 0;
    for(int i=1;i<n;i++){
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        minSum += 2*c;
    }
    int maxDis = dfs(1, 0);
    minSum -= maxDis;
    cout<<minSum<<endl;
    return 0;
}
