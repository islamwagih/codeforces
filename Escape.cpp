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

int main(){

    fastInputOutput();
    screen.turnOf();

    double vp,vd,t,f,c;cin>>vp>>vd>>t>>f>>c;
    double pDis = t*vp;
    int bijous = 0;
    if(vp < vd){
        while(pDis < c){
            double td = pDis/(vd - vp); /// princess distance / change in speed
            pDis += td*vp; /// she will continue running and she will be at current position += td * its speed
            if(pDis >= c) /// if they meet at c we will not need a bijou
                break;
            pDis += f*vp + pDis/vd * vp; ///she will drop a bijou and continue running by f(time to go back for dragon)*princess speed + current position/dragon speed * princess speed
            bijous++;  ///increase number of bijous
        }
    }

    cout<<bijous<<endl;
    return 0;
}
