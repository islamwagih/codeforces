#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e2+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

vector<int> graph[105];
vector<int> topSort;
bool vis[105];
map<ll, int> mp;

//on index not on value
void dfs(int node){
    vis[node] = 1;
    for(int child:graph[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    topSort.push_back(node);
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        ll val;cin>>val;
        mp[val] = i;
        arr[i] = val;
    }
    for(auto& pr:mp){
        if(mp.find(2*pr.first) != mp.end()){
            graph[pr.second].push_back(mp[2*pr.first]);
        }
        if(pr.first%3 == 0 && mp.find(pr.first/3) != mp.end()){
            graph[pr.second].push_back(mp[pr.first/3]);
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(topSort.begin(), topSort.end());
    for(int i:topSort){
        cout<<arr[i]<<' ';
    }

    return 0;
}
