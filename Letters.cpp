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

const int N = 2e5+10;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;



int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    vector<ll> floor(n+1);
    floor[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>floor[i];
        floor[i]+=floor[i-1];
    }
    int fi = 0, sz = n+1;
    for(int i=0;i<m;i++){
        ll query;cin>>query;
        while(fi < sz && floor[fi] < query) fi++;
        cout<<fi<<' '<<query-floor[fi-1]<<endl;
    }
    return 0;
}
