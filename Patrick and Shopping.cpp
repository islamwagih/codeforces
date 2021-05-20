#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

ll getMin(ll d1, ll d2, ll d3)
{
    return min(min(2*d1+2*d2, d1+d2+d3), min(2*d1 + 2*d3, 2*d2 + 2*d3));
}

int main(){
    fastInputOutput();
    ll d1, d2, d3;
    cin>>d1>>d2>>d3;
    cout<<getMin(d1, d2, d3)<<endl;
    return 0;
}
