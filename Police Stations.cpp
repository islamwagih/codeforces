#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const ll N = 3e5+9;
const ll inf = 1e5+5;
const ll M = 2*N;
const ll mod = 1e9+7;

vector<int> shouldBeRemoved;
queue<pair<int, int>> Q;
vector<pair<int, int>> graph[N];
bool vis[N];
int main(){
    fastInputOutput();

    int n, k, d;
    cin>>n>>k>>d;

    for(int i=0;i<k;i++){
        int x;cin>>x;
        Q.push({x, 0});
    }

    for(int i=0;i<n-1;i++){
        int u, v;cin>>u>>v;
        graph[u].push_back({v, i+1});
        graph[v].push_back({u, i+1});
    }

    while(Q.size()){
        int currCity = Q.front().F;
        int from = Q.front().S;
        Q.pop();
        if(vis[currCity]) continue;
        vis[currCity] = 1;
        for(auto pr:graph[currCity]){
            int child = pr.F;
            int edgeNum = pr.S;
            if(child != from){
                if(vis[child]) shouldBeRemoved.push_back(edgeNum);
                else Q.push({child, currCity});
            }
        }
    }

    cout<<shouldBeRemoved.size()<<endl;
    for(int edge:shouldBeRemoved) cout<<edge<<' ';cout<<endl;

    return 0;
}
