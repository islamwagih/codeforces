#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
//multi indexedSet -> less_equal<int>/greater_equal<int>
//indexedSet -> less<int>/greater<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
*/

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 2e2+5;
const int inf = 1e9;

int frq[26];
int main(){

    fastInputOutput();

    string s, t;cin>>s>>t;
    for(char c:s) frq[c-'a']++;
    for(char c:t) frq[c-'a']--;

    for(int i=0;i<26;i++) if(frq[i] < 0){
        cout<<"need tree\n";
        return 0;
    }

    if(s.size() == t.size()){
        cout<<"array\n";
        return 0;
    }

    string toConstruct = "";
    int start = 0;
    for(char c:s){
        if(start < t.size()) if(c == t[start]) toConstruct += c, start++;
    }

    if(toConstruct == t){
        cout<<"automaton\n";
    }else{
        cout<<"both\n";
    }

    return 0;
}
