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

unordered_map<int, int> frq;

int main(){
    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        frq[val]++;
    }
    int minPockets = -1;
    for(auto it:frq){
        if(it.second > minPockets){
            minPockets = it.second;
        }
    }
    cout<<minPockets<<endl;

    return 0;
}
