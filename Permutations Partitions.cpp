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

const int N = 2e5 + 5;
int perm[N];
int n, k;
int main(){
    fastInputOutput();
    cin>>n>>k;
    ll sum = 0, partitions = 1;
    vector<int> index;
    for(int i=0;i<n;i++){
        cin>>perm[i];
        if(perm[i] >= n-k+1){
            sum+=perm[i];
            index.push_back(i);
        }
    }
    int sz = index.size();
    for(int i=1;i<sz;i++){
        partitions*=index[i]-index[i-1];
        partitions%=998244353;
    }
    cout<<sum<<' '<<partitions<<endl;
    return 0;
}
