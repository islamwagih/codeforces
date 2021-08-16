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
priority_queue<int, vector<int>, greater<int>> both, fOnly, sOnly;

int main(){

    fastInputOutput();
    screen.turnOf();

    int n, k;cin>>n>>k;
    int flikes = 0, slikes = 0, blikes = 0;

    while(n--){
        int t, f, s;cin>>t>>f>>s;
        if(f && !s){
            flikes++;
            fOnly.push(t);
        }
        if(s && !f){
            slikes++;
            sOnly.push(t);
        }
        if(s && f){
            blikes++;
            both.push(t);
        }
    }


    if(flikes+blikes < k || slikes+blikes < k){
        cout<<-1<<endl;
    }else{
        int total = 0;
        while(k){
            bool topEmpty = both.empty(), fEmp = fOnly.empty(), sEmp = sOnly.empty();
            if(!topEmpty && (!fEmp && !sEmp)){
                int topBoth = both.top();
                int f = fOnly.top(), s = sOnly.top();
                if(topBoth <= f+s){
                    both.pop();
                    total += topBoth;
                }else{
                    fOnly.pop();
                    sOnly.pop();
                    total += (f+s);
                }
            }else if(!topEmpty){
                total += both.top();
                both.pop();
            }else{
                total += fOnly.top()+sOnly.top();
                fOnly.pop();
                sOnly.pop();
            }
            k--;
        }
        cout<<total<<endl;
    }

    return 0;
}
