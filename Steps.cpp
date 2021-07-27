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

int getSteps(int& n, int& m, ll& x1, ll& y1, ll& dx, ll& dy){
    int low = 0, high = 1e9+1;
    ll first = -1, sec = -1, newX = -1, newY = -1;
    while(low < high-1){
        int mid = (low+high)/2;
        first = x1+mid*dx, sec = y1+mid*dy;
        if(first > 0 && first <= n && sec > 0 && sec <= m){
            low = mid;
            newX = first, newY = sec;
        }else{
            high = mid;
        }
    }
    if(newX != -1)
        x1 = newX, y1 = newY;
    return low;
}

int main(){

    fastInputOutput();
    screen.turnOf();

    ll totalSteps = 0;
    int n, m;cin>>n>>m;
    ll x1, y1;cin>>x1>>y1;
    int k;cin>>k;
    while(k--){
        ll dx, dy;cin>>dx>>dy;
        int res = getSteps(n, m, x1, y1, dx, dy);
        totalSteps += res;
        //cout<<"steps from binary search = "<<res<<" vector was = "<<dx<<' '<<dy<<endl;
        //cout<<"x1 = "<<x1<<" y1 = "<<y1<<endl;
    }
    cout<<totalSteps<<endl;
    return 0;
}
