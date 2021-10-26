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

const int N = 1e5+5;
const int inf = 2e9+1;

pair<int, int> start, finish;
map<pair<int, int>, bool> allowed;

int dx[8] = {+0, +0, +1, -1, +1, -1, +1, -1};
int dy[8] = {+1, -1, +0, +0, +1, -1, -1, +1};

int bfs(){
    queue<pair<int, int>> Q;
    Q.push({start.first, start.second});
    allowed[{start.first, start.second}] = 0;
    int dis = 0;
    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            int xo = Q.front().first, yo = Q.front().second;
            if(xo == finish.first && yo == finish.second) return dis;
            Q.pop();
            for(int k=0;k<8;k++){
                int newX = xo+dx[k];
                int newY = yo+dy[k];
                if(allowed[{newX, newY}]){
                    Q.push({newX, newY});
                    allowed[{newX, newY}] = 0;
                }
            }
        }
        dis++;
    }
    return -1;
}

int main(){
    fastInputOutput();
    cin>>start.first>>start.second;
    cin>>finish.first>>finish.second;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int r, a, b;
        cin>>r>>a>>b;
        while(a <= b) allowed[{r, a++}] = 1;
    }
    cout<<bfs()<<endl;
    return 0;
}
