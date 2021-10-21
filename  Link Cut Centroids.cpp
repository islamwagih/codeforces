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

vector<int> tree[N];
int sz[N];

int n, c1, c2;

void dfs(int node, int par){
    sz[node] = 1;
    for(int ch:tree[node]) if(ch != par){
        dfs(ch, node);
        sz[node] += sz[ch];
    }
}

void getCentroids(int node, int par){
    bool centriod = 1;
    int sumOfChilds = 0;
    for(int ch:tree[node]) if(ch != par){
        sumOfChilds += sz[ch];
        if(sz[ch] > n/2) centriod = 0;
    }
    if(centriod && n-(sumOfChilds+1) > n/2) centriod = 0;
    if(centriod){
        if(!c1) c1 = node;
        else c2 = node;
    }
    for(int ch:tree[node]) if(ch != par){
        getCentroids(ch, node);
    }
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) tree[i].clear(), sz[i] = 0;
        c1 = c2 = 0;
        for(int i=1;i<n;i++){
            int a, b;cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        dfs(1, -1);
        getCentroids(1, -1);
        if(!c2){
            cout<<tree[1][0]<<' '<<1<<endl;
            cout<<tree[1][0]<<' '<<1<<endl;
        }else{
            for(int c:tree[c2]) if(c != c1){
                cout<<c2<<' '<<c<<endl;
                cout<<c1<<' '<<c<<endl;
                break;
            }
        }
    }
    return 0;
}
