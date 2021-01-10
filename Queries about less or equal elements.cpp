#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,m;cin>>n>>m;
    int* arr = new int[n];
    int* secArr = new int[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>secArr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<m;i++){
        int total = 0;
        cout<<upper_bound(arr, arr+n, secArr[i])-arr<<' ';
    }
    cout<<endl;

    return 0;
}
