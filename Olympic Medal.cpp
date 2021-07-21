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

    ///max heap for r1
    int n;cin>>n;
    priority_queue<int> possibleValuesOfR1;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        possibleValuesOfR1.push(val);
    }

    ///max heap for p1
    int m;cin>>m;
    priority_queue<int> possibleValuesOfP1;
    for(int i=0;i<m;i++){
        int val;cin>>val;
        possibleValuesOfP1.push(val);
    }

    ///min heap for p2
    int k;cin>>k;
    priority_queue<int> possibleValuesOfP2;
    for(int i=0;i<k;i++){
        int val;cin>>val;
        possibleValuesOfP2.push(-1*val);
    }

    int a,b;cin>>a>>b;

    double r2 = possibleValuesOfP1.top()*b*pow(possibleValuesOfR1.top(), 2);
    r2 = r2/(a*possibleValuesOfP2.top()*-1 + b*possibleValuesOfP1.top());
    r2 = sqrt(r2);

    cout<<fixed<<setprecision(12)<<r2<<endl;

    return 0;
}
