#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;

map<int, string> mapper;

bool isDiff(string s, int i){
    set<char> test;
    for(char c:s) if(c != '-') test.insert(c);
    return test.size() == i;
}

bool isDec(string s){
    char lst = s[0];
    int sz = s.size();
    for(int i=1;i<sz;i++){
        if(s[i] == '-') continue;
        if(s[i] >= lst) return false;
        lst = s[i];
    }
    return true;
}



vector<string> split(string& stat, char d){
    int sz = stat.size();
    vector<string> result;
    int i=0;
    while(i<sz){
        string toPush = "";
        int j = i;
        while(j < sz && stat[j] != d){
            toPush += stat[j++];
        }
        result.push_back(toPush);
        i = j+1;
    }
    return result;
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<vector<int>> tracker(n, vector<int>(3, 0));
    for(int i=0;i<n;i++){
        int sz;cin>>sz;
        string name;cin>>name;
        mapper[i] = name;
        for(int j=0;j<sz;j++){
            string phoneNum;cin>>phoneNum;
            vector<string> seq = split(phoneNum, '-');
            //0 for taxi, 1 for pizza, 2 for girl
            if(isDiff(phoneNum, 1)){
                tracker[i][0]++;
            }else if(isDec(phoneNum) && isDiff(phoneNum, 6)){
                tracker[i][1]++;
            }else{
                tracker[i][2]++;
            }
        }
    }

    vector<string> bestForTaxi, bestForPizza, bestForGirl;
    int bft = -1, bfp = -1, bfg = -1;
    for(int i=0;i<n;i++){
        if(tracker[i][0] > bft){
            bft = tracker[i][0];
        }
        if(tracker[i][1] > bfp){
            bfp = tracker[i][1];
        }
        if(tracker[i][2] > bfg){
            bfg = tracker[i][2];
        }
    }

     for(int i=0;i<n;i++){
        if(tracker[i][0] == bft){
            bestForTaxi.push_back(mapper[i]);
        }
        if(tracker[i][1] == bfp){
            bestForPizza.push_back(mapper[i]);
        }
        if(tracker[i][2] == bfg){
            bestForGirl.push_back(mapper[i]);
        }
    }

    cout<<"If you want to call a taxi, you should call: ";
    int taxiSz = bestForTaxi.size();
    for(int i=0;i<taxiSz-1;i++){
        cout<<bestForTaxi[i]<<", ";
    }
    cout<<bestForTaxi[taxiSz-1]<<".\n";

    cout<<"If you want to order a pizza, you should call: ";
    int pizzaSz = bestForPizza.size();

    for(int i=0;i<pizzaSz-1;i++){
        cout<<bestForPizza[i]<<", ";
    }
    cout<<bestForPizza[pizzaSz-1]<<".\n";

    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    int girlSz = bestForGirl.size();
    for(int i=0;i<girlSz-1;i++){
        cout<<bestForGirl[i]<<", ";
    }
    cout<<bestForGirl[girlSz-1]<<".\n";

    return 0;
}
