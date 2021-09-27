#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 5;
ll arr[N];
int n;


int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
       int a,b,c,m;
       cin>>a>>b>>c>>m;
       ll sum = a+b+c, maxElem = max(max(a, b), c);
       sum -= maxElem;
       maxElem -= sum;
       int minPairs = 0, maxPairs = (a-1)+(b-1)+(c-1);
       if(maxElem > 0) minPairs = maxElem-1;
       if(m >= minPairs && m <= maxPairs) cout<<"YES\n";
       else cout<<"NO\n";
    }
    return 0;
}
