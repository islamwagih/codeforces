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
const int N = 2e2+5;
const int inf = 1e9;
vector<int> graph[N];
bool vis[N];

int dfs(int node){
    vis[node] = 1;
    int ans = 1;
    for(int child:graph[node]){
        if(!vis[child]){
            ans += dfs(child);
        }
    }
    return ans;
}

int main(){

    fastInputOutput();
    ll ans = 1;
    int n, m;cin>>n>>m;
    while(m--){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int node=1;node<=n;node++){
        ll pw = 1;
        if(!vis[node]) pw = pow(2LL, dfs(node)-1);
        ans*=pw;
    }

    cout<<ans<<endl;

    return 0;
}
