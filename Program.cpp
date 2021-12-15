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

vector<vector<pair<int, int>>> buildTable(vector<int>& arr){
    int n = arr.size();
    vector<vector<pair<int, int>>> table(n, vector<pair<int, int>>(Log(n)+1));
    for(int i=0;i<n;i++) table[i][0].F = table[i][0].S = arr[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            table[i][j].F = min(table[i][j-1].F, table[i+(1<<(j-1))][j-1].F);
            table[i][j].S = max(table[i][j-1].S, table[i+(1<<(j-1))][j-1].S);
        }
    }
    return table;
}

pair<int, int> query(int l, int r, vector<vector<pair<int, int>>>& table){
    int len = r-l+1, j = Log(len);
    return {min(table[l][j].F, table[r-(1<<j)+1][j].F), max(table[l][j].S, table[r-(1<<j)+1][j].S)};
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, m;cin>>n>>m;
        string str;cin>>str;
        vector<int> arr(n+1);
        arr[0] = 0;
        for(int i=1;i<=n;i++) arr[i] = arr[i-1]+(str[i-1] == '+' ? 1:-1);
        auto table = buildTable(arr);
        while(m--){
            int l, r;cin>>l>>r;
            //left is not affected
            pair<int, int> left = query(0, l-1, table);
            pair<int, int> right = left;
            //affected by diff
            if(r != n){
                right = query(r+1, n, table);
                int diff = arr[r]-arr[l-1];
                right.F-=diff;
                right.S-=diff;
            }
            int mn = min(left.F, right.F), mx = max(left.S, right.S);
            cout<<mx-mn+1<<endl;
        }
    }
    return 0;
}
