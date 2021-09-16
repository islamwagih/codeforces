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
pair<int, int> arr[N];

bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first - a.second) > (b.first - b.second);
}

int main(){

    fastInputOutput();
    int n, m;cin>>n>>m;
    ll sum = 0;
    for(int i=0;i<n;i++){
        int v,u;cin>>v>>u;
        arr[i] = {v, u};
        sum += v;
    }

    sort(arr, arr+n, comp);

    int ans = 0, idx = 0;
    while(idx < n && sum > m){
        sum -= (arr[idx].first - arr[idx].second);
        ans++;
        idx++;
    }


    cout<<((sum <= m) ? ans:-1)<<endl;

    return 0;

}
