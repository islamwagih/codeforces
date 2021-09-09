#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

priority_queue<int> pq;
int main(){

    fastInputOutput();
    int n, k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        val*=-1;
        pq.push(val);
    }

    int delta = 0;
    while(k && !pq.empty()){
        int mn = pq.top()*-1;
        mn -= delta;
        if(mn > 0) cout<<mn<<endl;
        pq.pop();
        if(mn > 0) delta += mn, k--;
    }

    while(k--){
        cout<<0<<endl;
    }

    return 0;

}
