#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 5;

int lcm(int a, int b){
    return (a*b)/__gcd(a, b);
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        string a, b;cin>>a>>b;
        int sz1 = a.size(), sz2 = b.size();
        int maxSize = lcm(sz1, sz2);
        string newa = a, newb = b;
        while(newa.size() < maxSize) newa += a;
        while(newb.size() < maxSize) newb += b;
        if(newa != newb){
            cout<<-1<<endl;
        }else{
            cout<<newa<<endl;
        }
    }
    return 0;
}
