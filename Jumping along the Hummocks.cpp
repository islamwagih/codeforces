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

int n;
const int mx = 5+(2e5);
int arr[mx];
int cache[mx];
set<int>record[mx];
int frog(int i = 0){
    //base case
    if(i == n-1){
        return 0;
    }
    //transition
    if(cache[i]){
        ///found on cache
        return cache[i];
    }

    int ans1 = INT_MAX;
    auto it = record[arr[i]].upper_bound(i);
    if(it != record[arr[i]].end()){
        ///next ith position
        int idx = *it;
        ans1 = 1+frog(idx);
    }

    int ans2 = 1+frog(i+1); //go to next hill
    cache[i] = min(ans1, ans2);

    return cache[i];
}

int main(){

    fastInputOutput();
    screen.turnOf();

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        record[arr[i]].insert(i);
    }

    cout << frog() << endl;

    return 0;
}

