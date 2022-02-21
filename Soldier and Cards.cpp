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

const int N = 2e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;



int main(){
    fastInputOutput();
    int n;cin>>n;
    int x;cin>>x;
    queue<int> d1, d2;
    for(int i=0;i<x;i++){
        int v;cin>>v;
        d1.push(v);
    }
    int y;cin>>y;
    for(int i=0;i<y;i++){
        int v;cin>>v;
        d2.push(v);
    }
    bool oneWillWin = 1;
    int cnt = 0;
    while(oneWillWin){
        if(d1.empty()){
            cout<<cnt<<' '<<2<<endl;
            return 0;
        }
        if(d2.empty()){
            cout<<cnt<<' '<<1<<endl;
            return 0;
        }
        if(cnt == 1e6) oneWillWin = 0;
        int a = d1.front();d1.pop();
        int b = d2.front();d2.pop();
        if(a > b){
            d1.push(b);
            d1.push(a);
        }else{
            d2.push(a);
            d2.push(b);
        }
        cnt++;
    }
    cout<<-1<<endl;
    return 0;
}
