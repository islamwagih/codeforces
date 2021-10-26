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
int in[N], out[N];
bool vis[N];

int lastChild, ret;
void dfs(int node){
    vis[node] = 1;
    for(pair<int, int> pr:adj[node]){
        ret = min(ret, pr.second);
        if(!vis[pr.first]) dfs(pr.first);
    }
    if(lastChild == -1) lastChild = node;
}

int main(){
    fastInputOutput();
    int n,p;cin>>n>>p;
    for(int i=0;i<p;i++){
        int u, v, c;cin>>u>>v>>c;
        adj[u].push_back({v, c});
        in[v]++;
        out[u]++;
    }

    vector<pair<pair<int, int>, int>> vec;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            lastChild = -1, ret = INT_MAX;
            pair<pair<int, int>, int> triple;
            triple.second = -1;
            if(in[i] == 0 && out[i] == 1){
                dfs(i);
                triple.first = {i, lastChild};
                triple.second = ret;
            }
            if(triple.second != -1) vec.push_back(triple);
        }

    }

    sort(vec.begin(), vec.end());
    cout<<vec.size()<<endl;
    for(auto& t:vec){
        cout<<t.first.first<<' '<<t.first.second<<' '<<t.second<<endl;
    }


    return 0;
}
