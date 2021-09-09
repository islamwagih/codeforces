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
    int n;cin>>n;
    if(n < 4){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        int lowerLimit = (n%2 == 0) ? 4:5;
        for(int i=n;i>lowerLimit+1;i-=2){
            cout<<i<<" - "<<i-1<<" = "<<i-(i-1)<<endl;
            cout<<"1 * 1 = 1\n";
        }
        if(lowerLimit == 4){
            cout<<"1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        }else{
            cout<<"4 * 5 = 20\n2 - 1 = 1\n20 + 1 = 21\n21 + 3 = 24\n";
        }

    }


    return 0;

}
