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
int n, m;
int grid[105][105];

int main(){

    fastInputOutput();
    screen.turnOf();

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int r, c, val;
        cin>>r>>c>>val;
        grid[r-1][c-1] = val;
    }

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(grid[r][c] > 0){
                for(int ic=0;ic<n && grid[r][c] > 0;ic++){
                    if(grid[c][ic] > 0 && ic != r){
                        int delta = min(grid[r][c], grid[c][ic]);
                        grid[r][c] -= delta;
                        grid[r][ic] += delta;
                        grid[c][ic] -= delta;
                    }
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val = grid[i][j], mirror = grid[j][i];
            int delta = min(val, mirror);
            grid[i][j] -= delta;
            grid[j][i] -= delta;
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            ans += grid[i][j];
    }

    cout<<ans<<endl;

    return 0;
}
