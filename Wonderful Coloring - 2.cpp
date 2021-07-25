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


map<int, set<int>> mapToIndicies;

int main(){

    fastInputOutput();
    screen.turnOf();

    int t;cin>>t;
    while(t--){

        int n, k;cin>>n>>k;
        int* ans = new int[n];

        for(int i=0;i<n;i++){
            ans[i] = 0;
        }

        for(int i=0;i<n;i++){
            int val;cin>>val;
            if(mapToIndicies[val].size() < k){
                mapToIndicies[val].insert(i);
            }
        }

        int totalToBePaint = 0;
        for(auto& pr:mapToIndicies){
            totalToBePaint += pr.second.size();
        }

        ///to make it always divisible by k so we can always be sure that
        ///we have same number of blocks to paint for each color
        totalToBePaint -= totalToBePaint%k;

        int color = 0; bool out = 0;
        for(auto& pr:mapToIndicies){
            for(auto& idx:pr.second){
                if(totalToBePaint > 0){
                    ans[idx] = ++color;
                    color%=k;
                    totalToBePaint--;
                }else{
                    out = 1;
                }
            }
            if(out)
                break;
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<( i == n-1 ? "\n":" ");
        }

        delete[] ans;
        mapToIndicies.clear();
    }

    return 0;
}
