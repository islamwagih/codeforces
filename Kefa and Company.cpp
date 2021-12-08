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

pair<int, int> arr[N];
int n, d;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.F != b.F) return a.F < b.F;
    return a.S > b.S;
}

int main(){
    fastInputOutput();
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>arr[i].F>>arr[i].S;
    sort(arr, arr+n, comp);
    int l = 0, r = 0;
    ll mx = 0, curr = 0;
    while(l < n){
        while(r < n && abs(arr[r].F-arr[l].F) < d){
            curr+=arr[r].S;
            r++;
        }
        mx = max(mx, curr);
        curr-=arr[l].S;
        l++;
    }
    cout<<mx<<endl;
    return 0;
}
