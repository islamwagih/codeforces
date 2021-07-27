#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/**Not part of the solution it's just a logger to help me debug quickly**/
class Logger{
    bool loggerIsWorking = 1;
public:
    void log(const char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(char* msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void log(string& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
                cout<<msg<<endl;
            }
            }else{
        }
    }

    void log(string&& msg, long double val = INT_MIN){
        if(loggerIsWorking){
            if(val != INT_MIN){
                cout<<msg<<" "<<val<<endl;
            }else{
                cout<<msg<<endl;
            }
        }
    }

    void turnOf(){
        loggerIsWorking = 0;
    }

    void turnOn(){
        loggerIsWorking = 1;
    }

};

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

Logger screen;

bool comb(pair<double, int> f, pair<double, int> s){
    if(f.first == s.first){
        return f.second < s.second;
    }
    return f.first > s.first;
}

int main(){

    fastInputOutput();
    screen.turnOf();

    int n,t1,t2;cin>>n>>t1>>t2;
    double k;cin>>k;
    k/=100.0;
    vector<pair<double, int>> growers;

    for(int i=0;i<n;i++){
        int vi, zi;cin>>vi>>zi;
        pair<double, int> currGrower;
        double firstGrow = t1*vi;
        firstGrow -= (k*firstGrow);
        firstGrow += t2*zi;
        double secGrow = t1*zi;
        secGrow -= (k*secGrow);
        secGrow += t2*vi;
        currGrower.first = max(firstGrow, secGrow);
        currGrower.second = i+1;
        growers.push_back(currGrower);
    }

    sort(growers.begin(), growers.end(), comb);
    for(auto& grower:growers){
        cout<<grower.second<<' '<<fixed<<setprecision(2)<<grower.first<<endl;
    }

    return 0;
}
