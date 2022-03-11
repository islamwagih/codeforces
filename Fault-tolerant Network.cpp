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

ll maxCost;

void updateCost(ll& x){
    maxCost = min(maxCost, x);
}

int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        maxCost = 1e18;
        int n;cin>>n;
        vector<ll> a(n), b(n);
        for(ll& i:a) cin>>i;
        for(ll& i:b) cin>>i;
        //case-1
        ll currCost = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
        updateCost(currCost);
        //case-2
        currCost = abs(a[0]-b[n-1])+abs(a[n-1]-b[0]);
        updateCost(currCost);
        //case-3
        currCost = abs(a[0]-b[0]);
        ll minAtoBn = 1e18;
        for(int i=0;i<n;i++) minAtoBn = min(minAtoBn, abs(b[n-1]-a[i]));
        ll minBtoAn = 1e18;
        for(int i=0;i<n;i++) minBtoAn = min(minBtoAn, abs(b[i]-a[n-1]));
        currCost+=minAtoBn+minBtoAn;
        updateCost(currCost);
        //case-4
        currCost = abs(a[n-1]-b[n-1]);
        ll minAtoB0 = 1e18;
        for(int i=0;i<n;i++) minAtoB0 = min(minAtoB0, abs(b[0]-a[i]));
        ll minBtoA0 = 1e18;
        for(int i=0;i<n;i++) minBtoA0 = min(minBtoA0, abs(b[i]-a[0]));
        currCost+=minAtoB0+minBtoA0;
        updateCost(currCost);
        //case-5
        currCost = abs(a[0]-b[n-1]);
        ll minAnToBi = 1e18;
        for(int i=n-1;i>=0;i--) minAnToBi = min(minAnToBi, abs(a[n-1]-b[i]));
        ll minB0ToAi = 1e18;
        for(int i=0;i<n;i++) minB0ToAi = min(minB0ToAi, abs(b[0]-a[i]));
        currCost+=minAnToBi+minB0ToAi;
        updateCost(currCost);
        //case-6
        currCost = abs(a[n-1]-b[0]);
        ll bnToAi = 1e18;
        for(int i=0;i<n;i++) bnToAi = min(bnToAi, abs(b[n-1]-a[i]));
        ll a0ToBi = 1e18;
        for(int i=0;i<n;i++) a0ToBi = min(a0ToBi, abs(a[0]-b[i]));
        currCost+=a0ToBi+bnToAi;
        updateCost(currCost);
        //case-7
        ll a0, an, b0, bn;
        a0 = an = b0 = bn = 1e17;
        for(int i=0;i<n;i++) a0 = min(a0, abs(a[0]-b[i]));
        for(int i=n-1;i>=0;i--) an = min(an, abs(a[n-1]-b[i]));
        for(int i=0;i<n;i++) b0 = min(b0, abs(b[0]-a[i]));
        for(int i=n-1;i>=0;i--) bn = min(bn, abs(b[n-1]-a[i]));
        currCost = a0+an+b0+bn;
        updateCost(currCost);
        cout<<maxCost<<endl;
    }
    return 0;
}
