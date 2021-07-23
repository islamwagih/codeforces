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

int main(){

    fastInputOutput();
    screen.turnOf();

    int t;cin>>t;
    while(t--){
        string first, sec;cin>>first>>sec;
        set<string> subsOfFirst, subsOfSec;
        subsOfFirst.insert("");subsOfSec.insert("");
        for(int i=0;i<getSize(first);i++){
            for(int k=0;k<getSize(first);k++){
                string sub = first.substr(i, k+1);
                subsOfFirst.insert(sub);
            }
        }

        for(int i=0;i<getSize(sec);i++){
            for(int k=0;k<getSize(sec);k++){
                string sub = sec.substr(i, k+1);
                subsOfSec.insert(sub);
            }
        }

        int mn = 100;
        if(getSize(subsOfFirst) < getSize(subsOfSec)){
            for(auto& sub : subsOfFirst){
                if(subsOfSec.find(sub) != subsOfSec.end()){
                    ///this sub in the two of the strings
                    int op1 = getSize(first) - getSize(sub), op2 = getSize(sec) - getSize(sub);
                    mn = min(mn, op1+op2);
                }
            }
        }else{
            for(auto& sub:subsOfSec){
                if(subsOfFirst.find(sub) != subsOfFirst.end()){
                    ///this sub in the two of the strings
                    int op1 = getSize(first) - getSize(sub), op2 = getSize(sec) - getSize(sub);
                    mn = min(mn, op1+op2);
                }

            }
        }

        cout<<mn<<endl;
    }
    return 0;
}
