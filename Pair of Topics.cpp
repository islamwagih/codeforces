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
const int N = 2e5 + 5;
int A[N], B[N], C[N];

int main(){

    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++) C[i] = A[i] - B[i];
    sort(C, C+n);
    ll pairs = 0;
    for(int i=0;i<n;i++){
        int idx = upper_bound(C+i+1, C+n, -C[i])-C;
        if(idx != n){
            pairs += n-idx;
        }
    }
    cout<<pairs<<endl;
    return 0;

}

