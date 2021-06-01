#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

class Logger{
    bool loggerIsWorking = 1;
public:
    void log(char* msg, ll val){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void log(string& msg, ll val){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void log(string&& msg, ll val){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void turnOf(){
        loggerIsWorking = 0;
    }
    void turnOn(){
        loggerIsWorking = 1;
    }
};
int main(){
    fastInputOutput();
    Logger screen;
    int n, f;cin>>n>>f;
    vector<pair<int, int>> arr;
    vector<int> k, l;
    for(int i=0;i<n;i++){
        int t, q;cin>>t>>q;
        k.push_back(t), l.push_back(q);
        arr.push_back({min(2*t, q)-min(t, q), i});
    }
    sort(arr.rbegin(), arr.rend());
    ll sum = 0;
    for(int i=0;i<f;i++){
        int pos = arr[i].second;
        sum += min(2*k[pos], l[pos]);
    }
    for(int i=f;i<n;i++){
        int pos = arr[i].second;
        sum += min(k[pos], l[pos]);
    }
    cout<<sum<<endl;
    return 0;
}
 
