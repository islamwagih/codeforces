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

int arr[200];
set<int> swaps;
int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, m;cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=m;i++){
            int val;cin>>val;
            swaps.insert(val);
        }
        bool solved = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++){
                if(arr[j] > arr[j+1]){
                    if(swaps.find(j) == swaps.end()){
                        cout<<"NO\n";
                        solved = 0;
                        break;
                    }else{
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
            if(!solved){
                break;
            }
        }
        if(solved) cout<<"YES\n";
        swaps.clear();
    }
    return 0;

}
