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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    fastInputOutput();
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int val = arr[i]*2;
        auto it = upper_bound(arr.begin(), arr.end(), val);
        it--;
        if(it != arr.end()){
            int idx = it-arr.begin();
            int currAns = i+n-((it-arr.begin())+1);
            if(arr[idx] <= val)
                ans = min(ans, currAns);
        }
    }
    cout<<ans<<endl;
    return 0;
}
