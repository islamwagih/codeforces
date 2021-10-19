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

const int N = 1e3+5;
bool inStack[N], vis[N], cycle;
vector<int> graph[N];
queue<int> topSort;

void dfs(int node){
    vis[node] = 1;
    inStack[node] = 1;
    for(int child:graph[node]){
        if(!vis[child] && !inStack[child]) dfs(child);
        else if(inStack[child]) cycle = 1;
    }
    inStack[node] = 0;
    topSort.push(node);
}

int main(){

    fastInputOutput();
    int n;cin>>n;
    vector<string> names(n);
    for(int i=0;i<n;i++) cin>>names[i];
    for(int i=1;i<n;i++){
        int sz1 = names[i].size(), sz2 = names[i-1].size();
        bool equal = 1;
        for(int k=0;k<min(sz1, sz2);k++){
            char c = names[i][k], s = names[i-1][k];
            if(c != s){
                graph[c-'a'].push_back(s-'a');
                equal = 0;
                break;
            }
        }
        if(equal && sz2 > sz1){
            cout<<"Impossible\n";
            return 0;
        }
    }

    for(int i=0;i<26;i++){
        if(!vis[i])
            dfs(i);
    }
    if(cycle) cout<<"Impossible\n";
    else{
        while(topSort.size()){
            cout<<char(topSort.front()+'a');
            topSort.pop();
        }
        cout<<endl;
    }
    return 0;

}
