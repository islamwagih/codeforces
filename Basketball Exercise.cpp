#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
#define F first
#define S second


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void FIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

clock_t _stime, _etime;

inline void startTime(){
    _stime = clock();
}

inline void endTime(){
    _etime = clock();
}

inline void displayTime(){
    endTime();
    cerr<<(((double)_etime - _stime)/CLOCKS_PER_SEC)<<endl;
}


class Logger{
private:
    bool lock;
public:
    Logger(){
        lock = 0;
    }

    void on(){
        lock = 0;
    }

    void off(){
        lock = 1;
    }

    void bug(){
        if(!lock) cout<<endl;
    }

    template<typename T1, typename... T2>
    void bug(T1 a, T2... tail){
        if(!lock){
            cout<<a<<" ";
            bug(tail...);
        }
    }

};

Logger lg;

const int N = 1e5+5;
const int M = 2*N;
const int mod = 998244353;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;

int n;
ll dp[N][3];
ll arr1[N];
ll arr2[N];


ll solve(int i, int s){
    if(i == n) return 0;
    ll& ret = dp[i][s];
    if(~ret) return ret;
    if(s == 0){
        ret = max(solve(i+1, 0), max(arr1[i]+solve(i+1,2), arr2[i]+solve(i+1, 1)));
    }else if(s == 1){
        ret = max(solve(i+1, 0), arr1[i]+solve(i+1, 2));
    }else{
        ret = max(solve(i+1, 0), arr2[i]+solve(i+1, 1));
    }
    return ret;
}



int32_t main(){

    FIO();


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //startTime();

    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];

    cout<<solve(0, 0)<<endl;
    


    //displayTime();
    return 0;
}
