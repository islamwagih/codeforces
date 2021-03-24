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
    int a, b;
    cin>>a>>b;
    cout<<min(a, b)<<' '<<((a-min(a, b))+(b-min(a, b)))/2<<endl;
    return 0;
}

