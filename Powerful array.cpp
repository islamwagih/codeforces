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

const int N = 1e6+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

int frq[N];

struct Query{
    int i, l, r, bi;
    Query(int _l,int _r,int _i,int sqr):l(_l), r(_r), i(_i), bi(_l/sqr){}
    bool operator <(const Query& q2) const{
        if(bi!=q2.bi) return bi<q2.bi;
        return r<q2.r;
    }
};

vector<ll> arr;
vector<Query> queries;
ll val;

void add(int i){
    val += arr[i]*((2*frq[arr[i]])+1);
    frq[arr[i]]++;
}

void rmv(int i){
    frq[arr[i]]--;
    val -= arr[i]*((2*frq[arr[i]])+1);
}

vector<ll> Mo(){
    vector<ll> ans(queries.size());
    sort(queries.begin(), queries.end());
    int l = 1, r = 0;
    for(auto& q:queries){
        while(l<q.l) rmv(l++);
        while(l>q.l) add(--l);
        while(r<q.r) add(++r);
        while(r>q.r) rmv(r--);
        ans[q.i] = val;
    }
    return ans;
}

int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    arr = vector<ll>(n);
    for(ll& i:arr)cin>>i;
    int sqr = (int)ceil(sqrt(n));
    for(int i=0;i<m;i++){
        int l, r;cin>>l>>r;
        queries.push_back(Query(l-1, r-1, i, sqr));
    }
    auto ans = Mo();
    for(ll& x:ans) cout<<x<<endl;

    return 0;
}
