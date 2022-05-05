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

const int N = 2e5+5;
const int M = 2*N;
const int mod = 998244353;
const int OO = 0x3f3f3f3f;
const ll OOLL = 0x3f3f3f3f3f3f3f3f;



int32_t main(){

    FIO();


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //startTime();

    priority_queue<int> mxHeap;
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int cap;cin>>cap;
        mxHeap.push(cap);
        mnHeap.push(cap);
    }

    int maxProfit = 0, minProfit = 0;

    for(int i=0;i<n;i++)
    {
        int best = mxHeap.top();
        mxHeap.pop();
        maxProfit += best;
        if(best-1 > 0) mxHeap.push(best-1);
    }

    for(int i=0;i<n;i++)
    {
        int best = mnHeap.top();
        mnHeap.pop();
        minProfit += best;
        if(best-1 > 0) mnHeap.push(best-1);
    }

    cout<<maxProfit<<' '<<minProfit<<endl;

    //displayTime();
    return 0;
}
