#include <iostream>
using namespace std;
bool fastSearch(int arr[], int n, int target){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return true;
        }else if(arr[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}
int main(){
    int n, k;cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++){
        int query;cin>>query;
        if(fastSearch(arr, n, query)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
