#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){

    fastInputOutput();
    int n, k, total = 0;
    int* arr = new int[n];
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target = arr[k-1];
    for(int i=0;i<n;i++){
        if(arr[i] >= target && arr[i] != 0){
            total++;
        }
    }

    cout<<total<<endl;
    return 0;
}

