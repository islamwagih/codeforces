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
const int N = 1e5 + 5;
int arr[N];
int main(){

    fastInputOutput();
    int n,t;cin>>n>>t;
    for(int i=0;i<n;i++) cin>>arr[i];
    int l = 0, r = 0, mx = 0;
    while(l < n){
        while(r < n && arr[r] <= t){
            mx = max(mx, r-l+1);
            t-=arr[r];
            r++;
        }
        t+=arr[l++];
    }
    cout<<mx<<endl;
    return 0;

}
