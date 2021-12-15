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

const int N = 1e2+5;
const int inf = 1e8+5;
const int M = 2*N;
const int mod = 1e9+7;


int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        priority_queue<int> pq;
        vector<int> numes, denos;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            pq.push(x);
        }
        for(int i=0;i<k;i++){
            denos.push_back(pq.top());
            pq.pop();
        }
        for(int i=0;i<k;i++){
            numes.push_back(pq.top());
            pq.pop();
        }
        int ans = 0;
        while(pq.size()) ans+=pq.top(), pq.pop();
        for(int i=0;i<k;i++) ans+=numes[i]/denos[i];
        cout<<ans<<endl;
    }
    return 0;
}
