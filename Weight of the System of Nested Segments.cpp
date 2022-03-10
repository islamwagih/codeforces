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

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;

struct point{
    int p, w, ind;
    point(int _p, int _w, int _ind):p(_p), w(_w), ind(_ind){}
};

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
       vector<point> points;
       int n, m;cin>>n>>m;
       for(int i=1;i<=m;i++){
            int p, w;cin>>p>>w;
            points.push_back(point(p, w, i));
       }
       sort(points.begin(), points.end(), [](point a, point b){
            return a.w < b.w;});
        int minWeight = 0;
        for(int i=0;i<2*n;i++){
            minWeight+=points[i].w;
        }
        for(int i=2*n;i<m;i++) points.pop_back();
        sort(points.begin(), points.end(), [](point a, point b){
             return a.p < b.p;});
        int l = 0, r = points.size()-1;
        cout<<minWeight<<endl;
        while(n && l < r){
            cout<<points[l++].ind<<' '<<points[r--].ind<<endl;
            n--;
        }
    }
    return 0;
}
