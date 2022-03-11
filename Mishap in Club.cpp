#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;


int main(){
    fastInputOutput();
    string str;cin>>str;
    int mx = 0, mn = 0, total = 0;
    for(char c:str){
        if(c == '+') total++, mx = max(mx, total);
        else total--, mn = min(mn, total);
    }
    cout<<mx-mn<<endl;
    return 0;
}
