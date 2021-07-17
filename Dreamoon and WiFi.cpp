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

    string correctCommand;cin>>correctCommand;
    string receivedCommand;cin>>receivedCommand;

    int correctFinalPosition = 0;
    for(int i=0;i<(int)correctCommand.size();i++){
        correctFinalPosition += ((correctCommand[i] == '+') ? 1 : -1);
    }

    int numOfQuestionMark = 0, actualFinalPosition = 0;

    for(int i=0;i<(int)receivedCommand.size();i++){
            switch(receivedCommand[i]){
                case '+':
                    actualFinalPosition += 1;
                    break;
                case '-':
                    actualFinalPosition -= 1;
                    break;
                default:
                    numOfQuestionMark++;
            }
    }

    double ans = 0;
    if(numOfQuestionMark == 0){
        ans = (actualFinalPosition == correctFinalPosition) ? 1 : 0;
    }else{
        ///we have to bitmasking with the size of numOfQuestionMark and calculate the probability
        vector<int> possibleFinalPosition;
        int remainingSum = 0;
        for(int mask = 0;mask<(1<<numOfQuestionMark);mask++){
            remainingSum = 0;
            for(int i=0;i<numOfQuestionMark;i++){
                if(mask & (1<<i)){
                    remainingSum += 1;
                }else{
                    remainingSum -= 1;
                }
            }
            possibleFinalPosition.push_back(actualFinalPosition+remainingSum);
        }

        int countOfCorrectFinalPosition = 0;
        for(int solution:possibleFinalPosition){
            if(solution == correctFinalPosition){
                countOfCorrectFinalPosition++;
            }
        }

        ans = countOfCorrectFinalPosition/(double)possibleFinalPosition.size();

    }

    cout<<fixed<<setprecision(12)<<ans<<endl;

    return 0;
}

