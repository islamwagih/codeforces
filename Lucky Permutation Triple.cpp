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

const int N = 2e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;



int main(){
    fastInputOutput();
    int n;cin>>n;
    if(n%2 == 0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++) cout<<i<<' ';cout<<endl;
    for(int i=0;i<n;i++) cout<<i<<' ';cout<<endl;
    for(int i=0;i<n;i++) cout<<((i+i)%n)<<' ';cout<<endl;
    return 0;
}
