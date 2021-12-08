#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5+5;
const int inf = 1e9+5;
const int M = 2*N;


int main(){
    fastInputOutput();
    string a, b;cin>>a>>b;
    vector<int> ones(b.size(), 0), zeros(b.size(), 0);
    ones[0] = b[0] == '1';
    zeros[0] = b[0] == '0';
    for(int i=1;i<b.size();i++){
        ones[i] = ones[i-1]+(b[i]=='1');
        zeros[i] = zeros[i-1]+(b[i]=='0');
    }

    ll sum = 0;
    int sz = a.size();
    for(int i=0;i<a.size();i++){
        if(a[i] == '0'){
            sum += ones[b.size()-sz]-((i == 0) ? 0:ones[i-1]);
        }else{
            sum += zeros[b.size()-sz]-((i == 0) ? 0:zeros[i-1]);
        }
        sz--;
    }

    cout<<sum<<endl;

    return 0;
}
