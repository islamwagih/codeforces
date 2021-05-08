#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
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
    string s;cin>>s;
    map<string, int> substrs;
    for(int i=0;i<n-1;i++){
        string sub = "";
        sub+=s[i];
        sub+=s[i+1];
        substrs[sub]++;
    }
    int mx = -1;string maxStr = "";
    for(auto pr:substrs){
        if(pr.second > mx){
            mx = pr.second;
            maxStr = pr.first;
        }
    }
    cout<<maxStr<<endl;
    return 0;
}
