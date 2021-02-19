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
    int sz;cin>>sz;
    unordered_map<int, int> table;
    for(int i=0;i<sz;i++){
        int val;cin>>val;
        table[val]++;
    }

    if(sz == 1){
        cout<<"YES\n";
        return 0;
    }

    int maxOccur = (sz%2 == 0) ? sz/2 : sz/2+1;
    for(auto elem:table){
        if(elem.second > maxOccur){
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";
    return 0;
}
 
