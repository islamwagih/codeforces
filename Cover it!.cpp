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
vector<int> graph[N];
set<int> red, blue;
void dfs(int node, bool c){
    vis[node] = 1;
    if(c) red.insert(node);
    else blue.insert(node);
    for(int child:graph[node]){
        if(!vis[child]) dfs(child, !c);
    }
}
int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        red.clear(), blue.clear();
        for(int i=1;i<=n;i++){
            vis[i] = 0;
            graph[i].clear();
        }
        while(m--){
            int u, v;cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i, 1);
            }
        }
        if(red.size() < blue.size() && red.size() > 0){
            cout<<red.size()<<endl;
            for(int r:red) cout<<r<<' ';
        }else{
            cout<<blue.size()<<endl;
            for(int b:blue) cout<<b<<' ';
        }
        cout<<endl;
    }
    return 0;

}
