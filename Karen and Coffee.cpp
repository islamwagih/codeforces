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

const int N = (2e5)+5;

ll arr[N];

int main(){

    fastInputOutput();
    int n,k,q;cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        int l, r;cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }

    for(int i=1;i<N;i++){
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<N;i++){
        if(arr[i] < k){
            arr[i] = 0;
        }
        if(arr[i] > k){
            arr[i] = k;
        }
    }

    for(int i=1;i<N;i++){
        arr[i]+=arr[i-1];
    }

    while(q--){
        int l, r;cin>>l>>r;
        cout<<(arr[r]-arr[l-1])/k<<endl;
    }

    return 0;
}
