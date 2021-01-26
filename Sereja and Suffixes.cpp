#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bool seen[100001];
int ans[100001];

int main(){
    fastInputOutput();
    int n,m;cin>>n>>m;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>-1;i--){
        if(!seen[arr[i]]){
            seen[arr[i]] = 1;
            ans[i] = ans[i+1] + 1;
        }else{
            ans[i] = ans[i+1];
        }
    }
    for(int i=0;i<m;i++){
        int pos;cin>>pos;
        cout<<ans[pos-1]<<endl;
    }
    return 0;
}

