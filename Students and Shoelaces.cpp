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


map<int, set<int>> graph;
set<int> deletedNodes;

int main(){

    fastInputOutput();
    screen.turnOf();

    int n, m;cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    int k = 0;
    while(true){
        bool nothingToDelete = 1;

        for(auto& nodePair : graph){
            if((int)nodePair.second.size() == 1){
                deletedNodes.insert(nodePair.first);
                nothingToDelete = 0;
            }
        }

        if(nothingToDelete){
           break;
        }

        k++;
        for(auto& item : deletedNodes){
            graph.erase(item);
            for(auto& pr : graph){
                pr.second.erase(item);
            }
        }

        deletedNodes.clear();

    }

    cout<<k<<endl;

    return 0;
}
 
