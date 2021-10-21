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

const int N = 55;
const int inf = 2e9+1;

char matrix[N][N];
bool vis[N][N];

int dx[4] = {+1, -1, +0, +0};
int dy[4] = {+0, +0, -1, +1};

int n, m;
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}


void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int newi = i+dx[k];
        int newj = j+dy[k];
        if(valid(newi, newj) && matrix[newi][newj] != '#' && !vis[newi][newj]){
            dfs(newi, newj);
        }
    }
}

void resetVis(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vis[i][j] = 0;
        }
    }
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        vector<pair<int, int>> good, bad;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
                if(matrix[i][j] == 'G') good.push_back({i, j});
                if(matrix[i][j] == 'B') bad.push_back({i, j});
            }
        }

        ///if there is no good people simply block the escape cell
        if(good.size() == 0){
            cout<<"Yes\n";
            continue;
        }
        ///otherwise try to trap all bad people and check if we good can escape and bad can not
        bool adjGood = 0;
        for(auto& p:bad){
            for(int k=0;k<4;k++){
                int nx = p.first + dx[k];
                int ny = p.second + dy[k];
                if(valid(nx, ny) && matrix[nx][ny] == '.') matrix[nx][ny] = '#';
                if(valid(nx, ny) && matrix[nx][ny] == 'G'){
                    adjGood = 1;
                    break;
                }
            }
            if(adjGood) break;
        }

        if(adjGood){
            cout<<"No\n";
            continue;
        }

        ///if we block the exit then we can't do the task
        if(matrix[n-1][m-1] == '#' || (matrix[n-1][m-2] == '#' && matrix[n-2][m-1] == '#')){
            cout<<"No\n";
            continue;
        }


        ///test for each good position if we can escape and for each bad we can not

        bool solvable = 1;

        resetVis();
        dfs(n-1, m-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 'G' && !vis[i][j] || (matrix[i][j] == 'B' && vis[i][j])){
                    solvable = 0;
                    break;
                }
            }
            if(!solvable) break;
        }
        cout<<(solvable ? "Yes":"No")<<endl;
    }

    return 0;
}
