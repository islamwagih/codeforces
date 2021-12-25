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

const int N = 1e4+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;


vector<set<int>> chars(26);
int main(){
    fastInputOutput();
    string str;cin>>str;
    int n = str.size();
    for(int i=0;i<n;i++){
        char c = str[i];
        chars[c-'a'].insert(i);
    }
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type == 1){
           int pos;char newChar;
           cin>>pos>>newChar;
           pos--;
           chars[str[pos]-'a'].erase(pos);
           str[pos] = newChar;
           chars[newChar-'a'].insert(pos);
        }else{
            int l,r,ans=0;cin>>l>>r;
            l--,r--;
            for(int i=0;i<26;i++){
                auto it = chars[i].lower_bound(l);
                if(it != chars[i].end() && *it <= r) ans++;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
