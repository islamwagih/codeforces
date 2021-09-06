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

vector<int> vec;
int main(){

    fastInputOutput();
    int n, odd = 0, even = 0;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        vec.push_back(val);
        if(val%2) odd++;
        else even++;
    }

    if(odd > 0 && even > 0) sort(vec.begin(), vec.end());

    for(int val:vec) cout<<val<<' ';
    return 0;

}
