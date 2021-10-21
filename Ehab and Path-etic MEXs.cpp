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
int ans[N];

int main(){
    fastInputOutput();
    memset(ans, -1, sizeof(ans));

    int n;cin>>n;
    for(int edge=1;edge<n;edge++){
        int a, b;cin>>a>>b;
        tree[a].push_back(edge);
        tree[b].push_back(edge);
    }

    int smallestMax = 0;
    for(int i=1;i<=n;i++){
        if(tree[i].size() > 2){
            ans[tree[i][0]] = smallestMax++;
            ans[tree[i][1]] = smallestMax++;
            ans[tree[i][2]] = smallestMax++;
            break;
        }
    }

    for(int i=1;i<n;i++){
        if(ans[i] == -1){
            ans[i] = smallestMax++;
        }
        cout<<ans[i]<<endl;
    }

    return 0;
}
