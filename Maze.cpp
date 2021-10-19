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

const int N = 505;
const int inf = 2e9+1;

char matrix[N][N];
bool vis[N][N];
int n, m, k, cnt , s;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool valid(int x, int y){
    return x < n && x >= 0 && y < m && y >= 0;
}

void dfs(int x, int y){
    vis[x][y] = 1;
    cnt++;
    for(int d=0;d<4;d++){
        int newx = x+dx[d];
        int newy = y+dy[d];
        if(valid(newx, newy) && !vis[newx][newy] && matrix[newx][newy] == '.' && cnt < s-k){
            dfs(newx, newy);
        }
    }
}

int main(){
    fastInputOutput();
    cin>>n>>m>>k;
    int x, y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == '.') x = i, y = j, s++;
        }
    }
    dfs(x, y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == 0 && matrix[i][j] == '.') matrix[i][j] = 'X';
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}
