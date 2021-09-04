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

const int N = (1e5)+5;
int n, m, ans = 0;
bool visited[N];
bool cat[N];
vector<int> graph[N];
void dfs(int node, int cnt){
    visited[node] = 1;
    if(cat[node] == 1 && cnt < m){
        cnt++;
    }else if(cnt == m && cat[node] == 1){
        return;
    }else{
        cnt = 0;
    }
    if(graph[node].size() == 1 && visited[graph[node][0]] == 1 && cnt <= m){
        ans++;
    }
    for(int child:graph[node]){
        if(!visited[child]){
            dfs(child, cnt);
        }
    }

    if(cat[node] == 1){
        cnt--;
    }
}

int main(){

    fastInputOutput();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    for(int i=1;i<n;i++){
        int u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout<<ans<<endl;


    //cout<<graph[1].size()<<endl;
    return 0;

}
