#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

ll gcd(ll a, ll b){
     if(a%b == 0){
        return b;
     }
     return gcd(b, a%b);
}

int main(){
    fastInputOutput();
    ll low, high;cin>>low>>high;
    for(ll i=low;i<high-1;i++){
        for(ll j = i+1;j<high;j++){
            if(gcd(j, i) == 1){
                for(ll k = j+1;k<=high;k++){
                    if(gcd(k, j) == 1 && gcd(k, i) != 1){
                        cout<<i<<' '<<j<<' '<<k<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}

