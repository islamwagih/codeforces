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
    int n;cin>>n;
    int arr[3] = {0, 0, 0};
    for(int i=0;i<n;i++){
        int val;cin>>val;
        arr[i%3]+=val;
    }
    if(max(arr[1], arr[2]) < arr[0]){
        cout<<"chest\n";
    }else if(max(arr[0], arr[2]) < arr[1]){
        cout<<"biceps\n";
    }else{
        cout<<"back\n";
    }
    return 0;
}

