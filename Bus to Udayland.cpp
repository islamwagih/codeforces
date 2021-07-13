#include <bits/stdc++.h>
#include <chrono>
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

char matrix[1000][5];

int main(){

    fastInputOutput();
    screen.turnOf();

    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<5;k++){
            cin>>matrix[i][k];
        }
    }

    bool solved = 0;
    for(int i=0;i<n;i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == 'O'){
            matrix[i][0] = '+';
            matrix[i][1] = '+';
            solved = 1;
            break;
        }
        if(matrix[i][3] == matrix[i][4] && matrix[i][3] == 'O'){
            matrix[i][3] = '+';
            matrix[i][4] = '+';
            solved = 1;
            break;
        }
    }

    if(solved){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int k=0;k<5;k++){
                cout<<matrix[i][k];
            }
            cout<<endl;
        }
    }else{
        cout<<"NO\n";
    }

    return 0;
}

