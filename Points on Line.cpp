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

int bSearch(int* arr, int startIdx, int upper, int elem, int distance){
    int low = startIdx-1, high = upper;
    while(low < high-1){
        int mid = (low+high)/2;
        int diff = arr[mid] - elem;
        if(diff > distance){
            high = mid;
        }else{
            low = mid;
        }
    }
    return low;
}


int main(){

    fastInputOutput();
    screen.turnOf();

    int n, d;cin>>n>>d;
    int* points = new int[n];
    for(int i=0;i<n;i++){
        cin>>points[i];
    }
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        int idx = bSearch(points, i+1, n, points[i], d);
        //cout<<"idx = "<<idx<<" points[i] = "<<points[i]<<endl;
        if(idx  > i){
            ll val = (idx-i-1);
            ans += ((val*(val+1))/2);
        }
    }
    cout<<ans<<endl;
    delete[] points;
    return 0;
}
