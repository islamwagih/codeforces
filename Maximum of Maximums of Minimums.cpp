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
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;

int Log(int x){
    return 31-__builtin_clz(x);
}

vector<vector<int>> buildTable(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> table(n, vector<int>(Log(n)+1));
    for(int i=0;i<n;i++) table[i][0] = arr[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
    return table;
}

int query(int l, int r, vector<vector<int>>& table){
    int len = r-l+1, j = Log(len);
    return min(table[l][j], table[r-(1<<j)+1][j]);
}

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    vector<int>vec(n);
    int mn = INT_MAX, mx = INT_MIN;
    for(auto& i:vec) cin>>i, mn = min(mn, i), mx = max(mx, i);
    if(k == 1){
        cout<<mn<<endl;
    }else if(k == 2){
        int best = INT_MIN;
        auto table = buildTable(vec);
        for(int i=0;i<n-1;i++) best = max(best, max(query(0, i, table), query(i+1, n-1, table)));
        cout<<best<<endl;
    }else{
        cout<<mx<<endl;
    }
    return 0;
}
