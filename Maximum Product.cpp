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
int arr[N];

int main(){

    fastInputOutput();

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr, arr+n);
        vector<ll> probs;
        ll curr = 1;
        for(int i=0;i<5;i++){
            curr*=arr[i];
        }
        probs.push_back(curr);
        curr = 1;
        for(int i=n-5;i<n;i++){
            curr*=arr[i];
        }
        probs.push_back(curr);
        curr = 1;
        for(int i=0;i<2;i++){
            curr *= arr[i];
        }
        for(int i=n-3;i<n;i++){
            curr *= arr[i];
        }
        probs.push_back(curr);
        curr = 1;
        for(int i=0;i<4;i++){
            curr *= arr[i];
        }
        curr *= arr[n-1];
        probs.push_back(curr);
        cout<<*max_element(probs.begin(), probs.end())<<endl;
    }

    return 0;

}
