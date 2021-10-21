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

unordered_set<int> graph[N];
bool vis[N];
vector<char> ans;

void dfs(int node){
    ans.push_back(node+'a');
    vis[node] = 1;
    for(int ch:graph[node]){
        if(!vis[ch]) dfs(ch);
    }
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        ans.clear();
        for(int i=0;i<26;i++) graph[i].clear(), vis[i] = 0;
        string str;cin>>str;
        int sz = str.size();
        if(sz == 1){
            cout<<"YES\n";
            for(int i=0;i<26;i++) cout<<char(i+'a');
            cout<<endl;
            continue;
        }
        for(int i=0;i<sz-1;i++){
            graph[str[i]-'a'].insert(str[i+1]-'a');
            graph[str[i+1]-'a'].insert(str[i]-'a');
        }
        bool valid = 1;
        int startNode = -1;
        for(int i=0;i<26;i++){
            if(graph[i].size() > 2) valid = 0;
            else if(graph[i].size() == 1) startNode = i;
        }
        if(startNode == -1) valid = 0;
        if(!valid){
            cout<<"NO\n";
            continue;
        }
        dfs(startNode);
        for(int i=0;i<26;i++){
            if(!vis[i]) dfs(i);
        }
        cout<<"YES\n";
        for(char c:ans) cout<<c;
        cout<<endl;
    }
    return 0;
}
