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

const int N = 1e6+9;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;

set<int> afterMe, beforeMe;
int mapper[N];

int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int af, bf;
        cin>>af>>bf;
        afterMe.insert(af);
        beforeMe.insert(bf);
        mapper[af] = bf;
        if(af == 0) ans[1] = bf;
    }
    for(int id:afterMe){
        if(beforeMe.find(id) == beforeMe.end()){
            ans[0] = id;
            break;
        }
    }
    for(int i=2;i<n;i++) ans[i] = mapper[ans[i-2]];
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';cout<<endl;
    return 0;
}
