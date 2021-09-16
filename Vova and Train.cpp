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

int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int L,u,l,r;
        cin>>L>>u>>l>>r;
        cout<<L/u - (r/u - (l-1)/u)<<endl;
    }



    return 0;
}
