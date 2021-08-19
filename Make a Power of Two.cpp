#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define bint unsigned long long
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
vector<string> powersOfTwo;

int main(){

    fastInputOutput();
    screen.turnOf();

    for(bint i=1;i<=1e18;i*=2){
        powersOfTwo.push_back(to_string(i));
    }

    int t;cin>>t;
    while(t--){

        string str;cin>>str;
        int ans = INT_MAX;

        for(string& currPow:powersOfTwo){

            if(currPow == str){
                ans = 0;
                break;
            }

            int currAns = 0;
            int sz1 = str.size(), sz2 = currPow.size(), maxLen = 0;
            for(int i=0;i<sz1;i++){
                int currLen = 0;
                if(str[i] == currPow[0]){
                    int j = i, t = 0;
                    while(j < sz1 && t < sz2){
                        if(str[j] == currPow[t]){
                            t++, currLen++;
                        }
                        j++;
                    }
                    maxLen = max(currLen, maxLen);
                }
            }

            currAns += sz1-maxLen;
            currAns += sz2-maxLen;


            ans = min(ans, currAns);
        }

        cout<<ans<<endl;
    }

    return 0;
}
