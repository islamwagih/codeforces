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

const int N = 3e3;
vector<vector<int>> graph;
bool visited[N];
int n, ans = 0;

int dfs(int node){
    visited[node] = 1;
    int ans = 1;
    for(int child:graph[node]){
        if(!visited[child]){
            ans = max(1+dfs(child), ans);
        }
    }
    return ans;
}

int main(){
    fastInputOutput();
    cin>>n;
    graph = vector<vector<int>>(N);
    vector<int> roots;
    for(int i=1;i<=n;i++){
        int head;cin>>head;
        if(head == -1){
            roots.push_back(i);
        }else{
            graph[head].push_back(i);
        }
    }

    for(int root:roots){
        ans = max(ans, dfs(root));
    }

    cout<<ans<<endl;
    return 0;
}
