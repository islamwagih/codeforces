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
    int* arr = new int[3];
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    sort(arr, arr+3);
    cout<<(arr[1]-arr[0])+(arr[2]-arr[1])<<endl;
    delete[] arr;
    return 0;
}

