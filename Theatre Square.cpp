#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    int n,m,a;cin>>n>>m>>a;
    ll total = ceil(n/(double)a);
    ll heightNeeded = ceil(m/(double)a);
    cout<<total*heightNeeded<<endl;
    return 0;
}

