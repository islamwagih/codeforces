#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;

multiset<int> st;
int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> arr(n);
        for(ll& i:arr) cin>>i;
        ll evenGcd = 0;
        for(int i=0;i<n;i+=2){
            evenGcd = __gcd(evenGcd, arr[i]);
        }
        bool worked = 1;
        for(int i=1;i<n;i+=2){
            if(arr[i]%evenGcd == 0){
                worked = 0;
                break;
            }
        }
        if(worked){
            cout<<evenGcd<<endl;
            continue;
        }
        ll oddGcd = 0;
        for(int i=1;i<n;i+=2){
            oddGcd = __gcd(oddGcd, arr[i]);
        }
        worked = 1;
        for(int i=0;i<n;i+=2){
            if(arr[i]%oddGcd == 0){
                worked = 0;
                break;
            }
        }
        if(worked){
            cout<<oddGcd<<endl;
            continue;
        }
        cout<<0<<endl;

    }
    return 0;
}
