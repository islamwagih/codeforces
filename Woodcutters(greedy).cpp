#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
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

const int N = 1e2+9;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int main(){
    FIO();
    int n;cin>>n;
    vector<pair<int, int>> tree(n);
    for(int i=0;i<n;i++) cin>>tree[i].F>>tree[i].S;
    if(n <= 2){
        cout<<n<<endl;
        return 0;
    }
    int cnt = 2;
    bool lstLeftFell = 1, lstRightFell = 0;
    for(int i=1;i<n-1;i++){
        int left = tree[i].F-tree[i].S;
        int right = tree[i].F+tree[i].S;
        if(lstRightFell && left > tree[i-1].F+tree[i-1].S){
            lstLeftFell = 1;
            lstRightFell = 0;
            cnt++;
        }else if(!lstRightFell && left > tree[i-1].F){
            lstLeftFell = 1;
            lstRightFell = 0;
            cnt++;
        }else if(right < tree[i+1].F){
            lstRightFell = 1;
            lstLeftFell = 0;
            cnt++;
        }else{
            lstLeftFell = lstRightFell = 0;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
