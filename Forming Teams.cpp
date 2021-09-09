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
vector<int> graph[N];
int visited[N];
///returns 0 if path 1 if cycle
bool dfs(int node, int parent, int& edgeCount){
    if(visited[node]) return 1;
    visited[node] = 1;
    for(int child:graph[node]){
        if(child != parent){
           edgeCount++;
           if(dfs(child, node, edgeCount) == 1){
                return 1;
           }
        }
    }
    return 0;
}


int main(){

    fastInputOutput();
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int toRemove = 0;
    for(int node=1;node<=n;node++){
        if(!visited[node]){
            int edgeCount = 0;
            if(dfs(node, -1, edgeCount) == 1){
                toRemove += (edgeCount%2 == 1);
            }
        }
    }

    if((n-toRemove)%2 == 1) toRemove++;

    cout<<toRemove<<endl;



    return 0;

}
