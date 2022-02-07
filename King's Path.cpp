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

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};


int dx[8] = {-1, +1, +1, -1, +1, -1, +0, +0};
int dy[8] = {+0, +0, +1, +1, -1, -1, +1, -1};

bool valid(int x, int y){
    return x > 0 && y > 0 && x <= 1e9 && y <= 1e9;
}

unordered_set<pair<int, int>, pair_hash> allowed;

int bfs(int x1, int y1, int x2, int y2){
    queue<int> xs, ys;
    xs.push(x1), ys.push(y1);
    int steps = 0;
    allowed.erase({x1, y1});
    while(xs.size()){
        int sz = xs.size();
        while(sz--){
            int currX = xs.front();xs.pop();
            int currY = ys.front();ys.pop();
            if(currX == x2 && currY == y2) return steps;
            for(int k=0;k<8;k++){
                int newX = currX+dx[k];
                int newY = currY+dy[k];
                if(valid(newX, newY) && allowed.find({newX, newY}) != allowed.end()){
                    xs.push(newX);
                    ys.push(newY);
                    allowed.erase({newX, newY});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){

    fastInputOutput();
    allowed.reserve(1e5);
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    int n;cin>>n;
    while(n--){
        int r, a, b;cin>>r>>a>>b;
        while(a <= b) allowed.insert({r, a++});
    }

    cout<<bfs(x1, y1, x2, y2)<<endl;

    return 0;
}
