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
ll arr[N];
int n;

pair<int, int> bs(ll k){
    int low = -1, high = n;
    while(low < high-1){
        int mid = low+((high-low)/2);
        if(arr[mid] <= k)
            low = mid;
        else
            high = mid;
    }
    return {low, high};
}

int main(){
    fastInputOutput();
    cin>>n;
    ll sum = 0;
    for(int i=0;i<n;i++) cin>>arr[i], sum+=arr[i];
    sort(arr, arr+n);
    int m;cin>>m;
    while(m--){
        ll x, y;cin>>x>>y;
        pair<int, int> lowAndHigh = bs(x);
        int low = -1, high = -1;
        if(lowAndHigh.first == -1){
            low = high = lowAndHigh.second;
        }else if(lowAndHigh.second == n){
            low = high = lowAndHigh.first;
        }else{
            low = lowAndHigh.first, high = lowAndHigh.second;
        }

        ll minCoins1 = 0, minCoins2 = 0;
        if(arr[low] < x){
            minCoins1 += x-arr[low];
        }

        if(arr[high] < x){
            minCoins2 += x-arr[high];
        }

        if(sum-arr[low] < y){
            minCoins1 += y-(sum-arr[low]);
        }

        if(sum - arr[high] < y){
            minCoins2 += y-(sum-arr[high]);
        }
        cout<<min(minCoins1, minCoins2)<<endl;
    }
    return 0;
}
