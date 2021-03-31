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
    string a, b;cin>>a>>b;
    string ans = "";
    int maxSize = a.length();
    for(int i=0;i<maxSize;i++){
        if(a[i] != b[i]){
            ans += "1";
        }else{
            ans += "0";
        }
    }
    cout<<ans<<endl;
    return 0;
}


