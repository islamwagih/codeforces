#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    ll* arr = new ll[n+1],* prefix = new ll[n+1],* prefixSorted = new ll[n+1];
    arr[0] = prefix[0] = prefixSorted[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        prefix[i] = arr[i]+prefix[i-1];
    }
    sort(arr, arr+(n+1));
    for(int i=1;i<=n;i++){
        prefixSorted[i] = arr[i]+prefixSorted[i-1];
    }
    int m;cin>>m;
    while(m--){
        int q,l,r;cin>>q>>l>>r;
        if(q == 1){
            ///result from prefix
            cout<<prefix[r]-prefix[l-1]<<endl;
        }else{
            ///result from prefixSorted
            cout<<prefixSorted[r]-prefixSorted[l-1]<<endl;
        }
    }
    delete[] arr, prefix, prefixSorted;
    return 0;
}

