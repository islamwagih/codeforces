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

set<int> minimalSet, maximalSet;

int main(){

    fastInputOutput();
    screen.turnOf();
    int t;cin>>t;

    while(t--){
        int n;cin>>n;
        int* arr = new int[n];
        int* minimalArr = new int[n];
        int* maximalArr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            minimalSet.insert(i+1);
            maximalSet.insert(i+1);
        }

        int mx = -1;
        ///let's full the min & max permutation
        for(int i=0;i<n;i++){
            if(arr[i] > mx){
                ///new max in it's correct position
                maximalSet.erase(mx);
                maximalArr[i] = minimalArr[i] = mx = arr[i];
                minimalSet.erase(mx);
            }else{
                ///for minimalArr get the first element in the minimalSet
                int first = *minimalSet.begin();
                minimalArr[i] = first;
                minimalSet.erase(first);
                ///for maximalArr get the element behind the max in the maximalSet
                auto it = maximalSet.find(mx);
                it--;
                int behind = *it;
                maximalArr[i] = behind;
                maximalSet.erase(behind);
            }
        }

        for(int i=0;i<n;i++){
            cout<<minimalArr[i]<<' ';
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            cout<<maximalArr[i]<<' ';
        }
        cout<<endl;

        delete[] arr;delete[] minimalArr;delete[] maximalArr;

        minimalSet.clear();
        maximalSet.clear();
    }
    return 0;
}
