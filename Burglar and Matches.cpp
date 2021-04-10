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

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    pair<int, int>* arr = new pair<int, int>[m];
    for(int i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+m, comp);
    ll total = 0;
    for(int i=0;i<m;i++){
        pair<int, int> curr = arr[i];
        if(curr.first <= n){
            total += curr.first*curr.second;
            n -= curr.first;
        }else{
            total += n*curr.second;
            n -= n;
        }
        if(n == 0){
            break;
        }
    }
    cout<<total<<endl;
    return 0;
}

