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

const int N = 1e2+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;

int cnt(vector<int>& arr, int x){
    int ans = 0;
    for(int i:arr) if(i <= x) ans++;
    return ans;
}

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    vector<int> arr(n);
    for(int& i:arr) cin>>i;
    int low = 0, high = 1e9+1;
    while(low < high-1){
        int mid = (low+high)/2;
        if(cnt(arr, mid) <= k){
            low = mid;
        }else{
            high = mid;
        }
    }
    if(low > 0 && cnt(arr, low) == k){
        cout<<low<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}
