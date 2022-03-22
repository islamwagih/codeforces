#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int n, mxn;
int dp[N], cnt[N], nxt[N], endOfSeg[N];
vector<int> points;

void fillNxt(){
    set<int> biggestEnd;
    for(int i=0;i<mxn;i++){
        if(endOfSeg[i]) biggestEnd.insert(endOfSeg[i]);
        nxt[i] = biggestEnd.empty() ? i:(*biggestEnd.rbegin());
        biggestEnd.erase(i);
    }
}


void print(int i){
    if(i == mxn-1) return;
    int op = dp[i];
    if(op == dp[i+1]){
        print(i+1);
    }else{
        points.push_back(i);
        print(nxt[i]+1);
    }
}

int main(){
    FIO();
    cin>>n;
    mxn = 4*n;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        endOfSeg[l] = max(endOfSeg[l], r);
        cnt[l]++, cnt[r+1]--;
    }
    for(int i=1;i<mxn;i++) cnt[i] += cnt[i-1];
    fillNxt();
    for(int i=mxn-2;i>=0;i--) dp[i] = max(dp[i+1], cnt[i]+dp[nxt[i]+1]);
    if(dp[0] == n){
        print(0);
        cout<<points.size()<<endl;
        for(int& i:points) cout<<i<<' ';
    }else{
        cout<<-1<<endl;
    }
    return 0;
}
