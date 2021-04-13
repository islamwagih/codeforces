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

multimap<char, int> letterToIdx;

int main(){
    fastInputOutput();
    int n,k;cin>>n>>k;
    vector<pair<char, bool>> str;
    str.resize(400100);
    for(int i=0;i<n;i++){
        cin>>str[i].first;
        str[i].second = 0;
        letterToIdx.insert({str[i].first, i});
    }
    for(auto& it:letterToIdx){
        if(k == 0){
            break;
        }
        it.second = -1;
        k--;
    }
    for(auto it:letterToIdx){
        if(it.second == -1){
            continue;
        }
        str[it.second].second = 1;
    }
    for(auto it:str){
        if(it.second == 1){
            cout<<it.first;
        }
    }
    cout<<endl;
    return 0;
}
