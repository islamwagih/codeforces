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

#define point pair<int, int>

int main(){

    fastInputOutput();
    int n, x, y;cin>>n>>x>>y;
    set<point> slopes;

    for(int i=0;i<n;i++){
        int xi, yi;cin>>xi>>yi;
        int numerator = x-xi, denominator = y-yi;
        int sign = ((numerator < 0 && denominator > 0)||(numerator > 0 && denominator < 0)) ? -1:1;
        numerator = abs(numerator), denominator = abs(denominator);
        int div = __gcd(numerator, denominator);
        numerator/=div, denominator/=div;
        slopes.insert({sign*numerator, denominator});
    }

    cout<<slopes.size()<<endl;

    return 0;
}
