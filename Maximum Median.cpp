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
int n, k;
int arr[N];
bool ok(ll mid){
    if(arr[n/2] >= mid) return true;
    ll sum = 0;
    for(int i=n/2;i<n;i++){
        if(arr[i] >= mid) break;
        sum += mid-arr[i];
        if(sum > k) return false;
    }
    return sum <= k;
}

int main(){

    fastInputOutput();
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    ll low = arr[n/2]-1, high = arr[n/2]+k+1;
    while(low < high-1){
        ll mid = low+(high-low)/2;
        if(ok(mid)){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<low<<endl;
    return 0;

}

