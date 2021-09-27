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
map<int, int> omp, emp;
int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        omp.clear(), emp.clear();
        int n;cin>>n;
        vector<int> odd(n), even(n);
        for(int i=0;i<n;i++) cin>>odd[i], omp[odd[i]] = i;
        for(int i=0;i<n;i++) cin>>even[i], emp[even[i]] = i;
        if(even[0] > odd[0]){
            cout<<0<<endl;
            continue;
        }
        int ans = INT_MAX, j = 0;
        for(int i=1;i<=n*2;i+=2){
            while(even[j] < i) j++;
            ans = min(ans, omp[i]+emp[even[j]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
