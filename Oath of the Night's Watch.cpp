#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int* arr = new int[n];
    int mn = INT_MAX, mx = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] > mx){
            mx = arr[i];
        }
        if(arr[i] < mn){
            mn = arr[i];
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > mn && arr[i] < mx){
            total++;
        }
    }
    cout<<total<<endl;
    return 0;
}

