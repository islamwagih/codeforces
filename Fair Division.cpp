#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
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

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ones = 0, twos = 0;
        while(n--){
            int val;cin>>val;
            if(val == 1) ones++;
            else twos++;
        }
        if(twos%2 == 1){
            ones-=2;
        }
        cout<<((ones%2 == 0 && ones >= 0) ? "YES":"NO")<<endl;
    }

    return 0;
}
