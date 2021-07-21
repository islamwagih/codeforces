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

Logger screen;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bool isOverlapped(pair<int, int> x, pair<int, int> y){
    if(x.second < y.first){
        return false;
    }
    if(y.second < x.first){
        return false;
    }
    return true;
}

int main(){

    fastInputOutput();
    screen.turnOf();

    int p,q,l,r;cin>>p>>q>>l>>r;
    vector<pair<int, int>> zOnline, xOnline;

    for(int i=0;i<p;i++){
        int x, y;cin>>x>>y;
        zOnline.push_back({x, y});
    }

    for(int i=0;i<q;i++){
        int x, y;cin>>x>>y;
        xOnline.push_back({x, y});
    }

    int t = 0;

    for(int i=l;i<=r;i++){
        bool overlapped = 0;
        for(int k=0;k<q;k++){
            pair<int, int> currInterval = xOnline[k];
            currInterval.first += i, currInterval.second += i;
            for(int n=0;n<p;n++){
                if(isOverlapped(currInterval, zOnline[n])){
                    overlapped = 1;
                    break;
                }
            }
            if(overlapped){
                break;
            }
        }
        if(overlapped){
            t++;
        }
    }

    cout<<t<<endl;
    return 0;
}
