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
map<int, int> record;
set<int> secTeam;
int main(){

    fastInputOutput();
    screen.turnOf();

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            record[val]++;
            secTeam.insert(val);
        }

        ll mostFreqKey = -1, occ = -1, ans = 0;

        for(auto& pr:record){
            if(pr.second > occ){
                mostFreqKey = pr.first;
                occ = pr.second;
            }
            ans += pr.second;
        }

        //cout<<secTeam.size()<<endl;
        ll ans2 = secTeam.size()-1;
        //cout<<"set ans = "<<ans2<<" occ = "<<occ<<endl;

        if(ans2 == occ){
            cout<<ans2<<endl;
        }else if(occ > ans2 && occ-ans2 > 1){
            cout<<ans2+1<<endl;
        }else{
            cout<<min(occ, ans2)<<endl;
        }
        record.clear();
        secTeam.clear();
    }
    return 0;
}
