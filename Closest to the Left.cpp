#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++){
        int query;cin>>query;
        auto it = upper_bound(arr, arr+n, query);
        cout<<it-arr<<endl;
    }
    return 0;
}
