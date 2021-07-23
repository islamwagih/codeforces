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
       int n, k;cin>>n>>k;
       string str;cin>>str;

       int first = -1, last = -1, cnt = 0, sz = getSize(str);
       for(int i=0;i<sz;i++){
            if(str[i] == '*'){
                str[i] = 'x';
                cnt++;
                first = i;
                break;
            }
       }

       for(int i=sz-1;i>-1;i--){
            if(str[i] == '*'){
                str[i] = 'x';
                cnt++;
                last = i;
                break;
            }
       }

       for(int i=first;i<last;i++){
           if(str[i] != 'x'){
                continue;
           }

           int idx = i+k;
           if(idx >= last){
                break;
           }

           while(str[idx] != '*'){
                idx--;
           }

           if(idx != i){
                str[idx] = 'x';
                cnt++;
           }
       }

       cout<<cnt<<endl;

    }
    return 0;
}
