#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<pair<int, int>> vec;

int isFound(int x){
    int badPairs = 0;
    vector<int> frq(n+7, 0);
    for(int i=0;i<m;i++){
        if(vec[i].first == x || vec[i].second == x){
            continue;
        }
        badPairs++;
        frq[vec[i].first]++;
        frq[vec[i].second]++;
    }
    if(badPairs == 0){
        return -2;
    }
    for(int i=0;i<n+7;i++){
        if(frq[i] == badPairs){
            return i;
        }
    }
    return -1;
}

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    cin>>n>>m;
    vec.resize(m);
    for(int i=0;i<m;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    if(isFound(vec[0].first) != -1){
        cout<<"YES\n";
    }else if(isFound(vec[0].second) != -1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}

