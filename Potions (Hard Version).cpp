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

const int N = 2e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;

int main(){

    fastInputOutput();
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
        sum += x;
        while(sum < 0){
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<pq.size()<<endl;
    return 0;
}
