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
    int n, total = 0;
    cin>>n;
    while(n--){
        int p,q;cin>>p>>q;
        if(abs(p-q) >= 2){
            total++;
        }
    }
    cout<<total<<endl;
    return 0;
}

