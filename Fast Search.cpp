#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    sort(arr, arr+n);
    while(k--){
        int l,h;
        cin>>l>>h;
        auto low = lower_bound(arr, arr+n, l);
        auto high = upper_bound(arr, arr+n, h);
        cout<<high-low<<endl;
    }
    return 0;
}
