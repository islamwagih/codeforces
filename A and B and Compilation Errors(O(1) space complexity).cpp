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
    ull a = 0, b = 0, c = 0;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        a += val;
    }

    for(int i=0;i<n-1;i++){
        int val;cin>>val;
        b += val;
    }

    for(int i=0;i<n-2;i++){
        int val;cin>>val;
        c += val;
    }

    cout<<a-b<<endl;
    cout<<b-c<<endl;

    return 0;
}
