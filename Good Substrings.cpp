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

const int N = 1e5+5;
const int inf = 1e9+5;
const int M = 2*N;

ll egcd(ll a, ll b, ll &x, ll &y){ /// ax + by = gcd(a,b)
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll g=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

ll modInverse(ll a, ll m){ /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x,y,g;
    g=egcd(a,m,x,y);
    if(g>1)
        return -1;
    return (x+m)%m;
}

ll fixMod(ll a, ll m){
    return (a + m)%m;
}

ll pushBack(ll h, ll x, ll p, char ch){
    return (((h*x)%p)+ch)%p;
}

ll pushFront(ll h, ll xp, ll p, char ch){ // xp=XP[len]
    return (h+(xp*ch)%p)%p;
}

ll popBack(ll h, ll x, ll p, char ch){
    return (fixMod(h-ch,p)*modInverse(x,p))%p;
}

ll popFront(ll h, ll xp, ll p, char ch){ // xp=XP[len-1]
    return fixMod(h-((xp*ch)%p),p);
}

set<pair<int, int>> subs;
bool seq[26];

int main(){
    fastInputOutput();
    ll x = 128, p1 = 1e9+7, p2 = 1e9+9;
    vector<ll> XP1(1605), XP2(1605);
    XP1[0] = XP2[0] = 1;
    for(int i=1;i<=1600;i++) XP1[i] = (XP1[i-1]*x)%p1, XP2[i] = (XP2[i-1]*x)%p2;
    string str;cin>>str;
    for(int i=0;i<26;i++){
        char c;cin>>c;
        if(c == '1') seq[i] = 0;
        else seq[i] = 1;
    }
    int k, sz = str.size();cin>>k;
    for(int i=0;i<sz;i++){
        int currBad = seq[str[i]-'a'];
        ll h1 = 0, h2 = 0;
        h1 = pushBack(h1, x, p1, str[i]);
        h2 = pushBack(h2, x, p2, str[i]);
        if(currBad <= k) subs.insert({h1, h2});
        for(int j=i+1;j<sz;j++){
            h1 = pushBack(h1, x, p1, str[j]);
            h2 = pushBack(h2, x, p2, str[j]);
            currBad+=seq[str[j]-'a'];
            if(currBad <= k){
                subs.insert({h1, h2});
            }
            else break;
        }
    }
    cout<<subs.size()<<endl;
    return 0;
}
