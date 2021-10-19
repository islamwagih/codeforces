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

const int N = 55;
const int inf = 2e9+1;

int main(){
    fastInputOutput();
    ll n, a, b;
    cin>>n>>a>>b;
    vector<int> vec(n);
    for(auto&i:vec) cin>>i;
    for(int w:vec){
        ll low = -1, high = w+1, mx = (w*a)/b;
        while(low < high-1){
            ll mid = low+(high-low)/2;
            if((mid*a)/b >= mx) high = mid;
            else low = mid;
        }
        cout<<w-high<<' ';
    }
    cout<<endl;
    return 0;
}
