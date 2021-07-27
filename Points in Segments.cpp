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
vector<pair<int, int>> segments;
vector<int> points;
int main(){

    fastInputOutput();
    screen.turnOf();

   int n, m;cin>>n>>m;
   for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        segments.push_back({a, b});
   }

   for(int point=1;point<=m;point++){
        bool sharedInSeg = 0;
        for(auto& seg : segments){
            if((point >= seg.first && point <= seg.second)){
                ///in the segment
                sharedInSeg = 1;
                break;
            }
        }
        if(!sharedInSeg){
            points.push_back(point);
        }
   }

   cout<<points.size()<<endl;
   for(auto& point:points){
        cout<<point<<' ';
   }


    return 0;
}
