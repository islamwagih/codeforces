#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i+=2){
        if(arr[i-1] < arr[i-2]){
            swap(arr[i-1], arr[i-2]);
        }
    }
    for(int i=3;i<=n;i+=2){
        if(arr[i-1] > arr[i-2]){
            swap(arr[i-1], arr[i-2]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}