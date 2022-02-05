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

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;

int main(){
    fastInputOutput();
    int n;cin>>n;
    string s;cin>>s;
    string valid = "";
    int i = 0;
    while(i < n && s[i] == '0') i++;
    while(i < n){
        if(s[i] != '1') valid+=s[i];
        i++;
    }
    map<char, string> mp;
    for(char i:{'2', '3', '5', '7'}) mp[i] = i;
    mp['4'] = "223";
    mp['6'] = "35";
    mp['8'] = "2227";
    mp['9'] = "2337";
    string ans = "";
    for(char c:valid) ans+=mp[c];
    sort(ans.rbegin(), ans.rend());
    cout<<ans<<endl;
    return 0;
}
