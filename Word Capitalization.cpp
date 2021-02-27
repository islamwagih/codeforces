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
    string str;cin>>str;
    if(str[0] >= 97 ){
        str[0] -= 32;
    }
    cout<<str<<endl;
    return 0;
}


