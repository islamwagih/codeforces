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

const int N = (1e5)+7;
ll arr[N];
ll p[N];
ll fq[N];
vector<pair<pair<int, int>, int>> ranges;
int main(){

    fastInputOutput();
    int n, m, k;cin>>n>>m>>k;
    ranges.resize(m+5);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=m;i++){
        pair<int, int> r;int v;
        cin>>r.first>>r.second>>v;
        ranges[i] = {r, v};
    }


    for(int i=0;i<k;i++){
        int l, r;cin>>l>>r;
        fq[l]++, fq[r+1]--;
    }

    for(int i=1;i<=m;i++){
        fq[i]+=fq[i-1];
    }


    for(int i=1;i<=m;i++){
        ll val = fq[i]*ranges[i].second;
        int inL = ranges[i].first.first;
        int inR = ranges[i].first.second;
        p[inL]+=val;
        p[inR+1]-=val;
    }



    for(int i=1;i<=n;i++){
        p[i]+=p[i-1];
    }

    for(int i=1;i<=n;i++){
        arr[i]+=p[i];
        cout<<arr[i]<<' ';
    }


    return 0;
}
