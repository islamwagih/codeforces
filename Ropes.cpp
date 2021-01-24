#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int fit(int arr[], int n, int k, double mid){
    int ropes = 0;
    for(int i=0;i<n;i++){
        ropes += arr[i]/mid;
    }
    return ropes;
}

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    double low, high, mid;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    high = 1e9, low = 0;
    while(low < high){
        mid = (low+high)/2.0;
        int totalRopes = fit(arr, n, k, mid);
        if(totalRopes >= k){
             low = mid+EPS;
        }else{
            high = mid-EPS;
        }
    }
    cout<<fixed<<setprecision(6)<<mid<<endl;
    return 0;
}

