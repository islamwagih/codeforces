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

///char to its indexes
map<char, set<int>> record;

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    ///1 -> visible and 0 -> invisible
    pair<char, bool>* str = new pair<char, bool>[n];
    for(int i=0;i<n;i++){
        cin>>str[i].first;
        str[i].second = 1; ///visible
        record[str[i].first].insert(i);
    }
    for(auto pr:record){
        for(auto idx:pr.second){
            if(k == 0){ break; }
            str[idx].second = 0;
            k--;
        }
    }
    for(int i=0;i<n;i++){
        if(str[i].second){
            cout<<str[i].first;
        }
    }
    delete[] str;
    return 0;
}
 
