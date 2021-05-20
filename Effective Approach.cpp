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
    pair<int, int>* record = new pair<int, int>[n+5];
    for(int i=0;i<n;i++){
        int val;cin>>val;
        pair<int, int> curr;
        curr.first = i+1;
        curr.second = n-i;
        record[val] = curr;
    }
    int m;cin>>m;
    ll vasya = 0, petya = 0;
    for(int i=0;i<m;i++){
        int val;cin>>val;
        vasya += record[val].first;
        petya += record[val].second;
    }
    cout<<vasya<<' '<<petya<<endl;
    delete[] record;
    return 0;
}
 