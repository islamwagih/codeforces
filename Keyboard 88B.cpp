#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

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
            }else{
                cout<<msg<<endl;
            }
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

char keyboard[35][35];
vector<pair<int, int>> shiftPos;
map<char, vector<pair<int, int>>> lettersPos;
map<char, bool> cache;
int n,m,x;

double ecludianDis(int x1, int y1, int x2, int y2){
    return sqrt(double((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}


int main(){
    fastInputOutput();
    Logger screen;
    screen.turnOf();
    cin>>n>>m>>x;

    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>keyboard[i][k];
            if(keyboard[i][k] == 'S'){
                shiftPos.push_back(make_pair(i, k));
            }else{
                lettersPos[keyboard[i][k]].push_back(make_pair(i, k));
            }
        }
    }

    int len, ans = 0;cin>>len;
    char* str = new char[len];
    for(int i=0;i<len;i++){
        cin>>str[i];
    }

    for(int i=0;i<len;i++){
        char curr = str[i];
        bool islower = (curr >= 97) ? 1:0;
        curr = tolower(curr);
        double dis = INT_MAX;

        if(lettersPos.find(curr) == lettersPos.end()){
            screen.log("this character is not exist in keyboard");
            cout<<-1<<endl;
            return 0;
        }

        ///if the character is lower character we can reach it with one hand so skip
        if(islower){
            continue;
        }

        ///return -1 if the character is capital and we don't have S on keyboard
        if((int)shiftPos.size() == 0){
            ///there is not Shift character on keyboard
            screen.log("return -1 because it's a upper case letter and we don't have S");
            cout<<-1<<endl;
            return 0;

        }

        ///Upper case character
        if(cache.find(curr) != cache.end()){
            ///we have answered this capital character before if it is false then we can
            ///reach it with one hand, if true reach with two hands so increment ans
            ans += (cache[curr] == 1) ? 1 : 0;
            continue;
        }


        ///get the min distance among all 'S'
        for(auto c : lettersPos[curr]){
            for(auto s: shiftPos){
                double currDis = ecludianDis(c.first, c.second, s.first, s.second);
                dis = min(dis, currDis);
            }
        }


        ///if the distance is greater than x then make ans++
        if(dis > x){
            screen.log("Increment ans because distance = ", dis);
            ans++;
            cache.insert({curr, 1});
        }else{
            cache.insert({curr, 0});
        }

    }

    cout<<ans<<endl;
    delete[] str;
    return 0;
}


