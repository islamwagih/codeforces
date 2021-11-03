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

const int N = 1e6+5;
const int inf = 2e9+1;

vector<string> maze;
vector<vector<bool>> reachable, reachable2;
int cnt[N];
int n, m;

void bfs()
{
	queue<pair<int, int> > Q;
	Q.emplace(0, 0);
	reachable[0][0] = true;
	while(!Q.empty())
	{
		int i = Q.front().F;
		int j = Q.front().S;
		Q.pop();
		if(i + 1 < n and maze[i + 1][j] != '#' and !reachable[i + 1][j])
		{
			Q.emplace(i + 1, j);
			reachable[i + 1][j] = true;
		}
		if(j + 1 < m and maze[i][j + 1] != '#' and !reachable[i][j + 1])
		{
			Q.emplace(i, j + 1);
			reachable[i][j + 1] = true;
		}
	}
}

void bfs2()
{
	queue<pair<int, int> > Q;
	Q.emplace(n - 1, m - 1);
	reachable2[n - 1][m - 1] = true;
	while(!Q.empty())
	{
		int i = Q.front().F;
		int j = Q.front().S;
		cnt[i + j] += reachable[i][j];
		Q.pop();
		if(i - 1 >= 0 and maze[i - 1][j] != '#' and !reachable2[i - 1][j])
		{
			Q.emplace(i - 1, j);
			reachable2[i - 1][j] = true;
		}
		if(j - 1 >= 0 and maze[i][j - 1] != '#' and !reachable2[i][j - 1])
		{
			Q.emplace(i, j - 1);
			reachable2[i][j - 1] = true;
		}
	}
}

int main(){
    fastInputOutput();
    cin>>n>>m;
    reachable = vector<vector<bool>> (n, vector<bool>(m, 0));
    reachable2 = vector<vector<bool>> (n, vector<bool>(m, 0));
    for(int i=0;i<n;i++){
        string str;cin>>str;
        maze.emplace_back(str);
    }
    bfs();
    if(!reachable[n-1][m-1]) return puts("0"), 0;
    bfs2();
    int mn = 2;
    for(int i=1;i<n+m-2;i++){
        mn = min(mn, cnt[i]);
    }
    cout<<mn<<endl;
    return 0;
}
