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
#define point pair<int, int>
#define print(_p) cout<<_p.first<<' '<<_p.second<<endl

double dis(point a, point b){
    double xs = a.first - b.first;
    double ys = a.second - b.second;
    xs = xs * xs;
    ys = ys * ys;
    return sqrt(xs+ys);
}

bool isCovered(point a, point b, int r){
    double m = dis(a, b);
    return m <= r;
}

int main(){

    fastInputOutput();
    screen.turnOf();

    point one, two, three, four;
    cin>>one.first>>one.second>>two.first>>two.second;
    int n;cin>>n;
    set<pair<point, int>> radiators;
    for(int i=0;i<n;i++){
        point p;cin>>p.first>>p.second;
        int r;cin>>r;
        radiators.insert({p, r});
    }

    three.first = one.first, three.second = two.second;
    four.first = two.first, four.second = one.second;

    vector<point> vec;
    set<point> allPoints;

    vec.push_back(one), vec.push_back(two), vec.push_back(three), vec.push_back(four);

    sort(vec.begin(), vec.end());


    for(int y=vec[0].second;y<=vec[1].second;y++){
        allPoints.insert({vec[0].first, y});
    }

    for(int y=vec[2].second;y<=vec[3].second;y++){
        allPoints.insert({vec[2].first, y});
    }

    for(int x=vec[1].first;x<=vec[3].first;x++){
        allPoints.insert({x, vec[1].second});
    }

    for(int x=vec[0].first;x<=vec[2].first;x++){
        allPoints.insert({x, vec[0].second});
    }


    int ans = 0;
    for(point p:allPoints){
        bool covered = 0;
        for(auto& rad:radiators){
            if(isCovered(p, rad.first, rad.second)){
                covered = 1;
                break;
            }
        }
        if(!covered)
            ans++;
    }

    cout<<ans<<endl;



    return 0;
}
