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

const int N = 1e5 + 5;

int in[N];
int out[N];
int used[N];

int main(){
    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>out[i];
    ll ans = 0;
    int l = 0, r = 0;
    while(l < n && r < n){
        while(l < n && used[in[l]] == 1) l++;
        if(l == n) break;
        if(in[l] != out[r]){
            ans++;
            used[out[r]] = 1;
        }else{
            l++;
        }
        r++;
    }
    cout<<ans<<endl;
    return 0;
}
