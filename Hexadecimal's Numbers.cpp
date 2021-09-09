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

int solve(ll num, int n){
    if(num > n) return 0;
    int ans = 1;
    ans += solve(num*10, n);
    ans += solve(num*10+1, n);
    return ans;
}

int main(){

    fastInputOutput();
    int n;cin>>n;
    cout<<solve(1, n)<<endl;

    return 0;

}
