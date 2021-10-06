#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
//multi indexedSet -> less_equal<int>/greater_equal<int>
//indexedSet -> less<int>/greater<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
*/

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 2e5+5;
const int inf = 1e9;

vector<int> graph[N];
bool vis[N];

///return connected component size and count number of edges in a reference variable
int dfs(int node, ll& edgeCnt){
    vis[node] = 1;
    int ccSize = 1;
    for(int child:graph[node]){
        edgeCnt++;
        if(!vis[child]){
            ccSize += dfs(child, edgeCnt);
        }
    }
    return ccSize;
}

int main(){

    fastInputOutput();
    int n, m;
    cin>>n>>m;
    while(m--){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int node=1;node<=n;node++){
        if(!vis[node]){
            ll edges = 0;
            int ccSize = dfs(node, edges);
            edges/=2;
            ll supposedEdges = ((1ll*ccSize)*(ccSize-1))/2LL;
            if(edges != supposedEdges){cout<<"NO\n";return 0;}
        }
    }
    cout<<"YES\n";
    return 0;
}
