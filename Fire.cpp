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

const int N = 1e3+5;
const int inf = 1e9+5;
const int M = 2*N;

struct item{
    int t, d, p, idx;
};

int n;
item arr[N];
int dp[105][2005];
int solve(int i, int c){
    if(i == n) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    int op1 = (arr[i].d > arr[i].t+c) ? arr[i].p+solve(i+1, arr[i].t+c):0;
    int op2 = solve(i+1, c);
    return dp[i][c] = max(op1, op2);
}

vector<item> items;
void print(int i, int c){
    if(i == n) return;
    int opt = solve(i, c);
    int op1 = (arr[i].d > arr[i].t+c) ? arr[i].p+solve(i+1, arr[i].t+c):0;
    int op2 = solve(i+1, c);
    if(opt == op1 && op1 != 0){
        items.push_back(arr[i]);
        print(i+1, arr[i].t+c);
    }else{
        print(i+1, c);
    }
}

bool comp(item a, item b){
    if(a.d == b.d) return a.p > b.p;
    return a.d < b.d;
}

int main(){
    fastInputOutput();
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].t>>arr[i].d>>arr[i].p;
        arr[i].idx = i+1;
    }
    sort(arr, arr+n, comp);
    cout<<solve(0, 0)<<endl;
    print(0, 0);
    cout<<items.size()<<endl;
    for(auto& i:items){
        cout<<i.idx<<' ';
    }
    return 0;
}
