#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    int sum = 0;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+n);
    int partialSum = 0, minCoins = 0, idx = n-1;
    while(partialSum <= sum && idx > -1){
        partialSum+=arr[idx];
        sum-=arr[idx];
        minCoins++;
        idx--;
    }
    cout<<minCoins<<endl;
    return 0;
}

