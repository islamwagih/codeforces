#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int strToInt(string num){
    int curr = 0, sz = num.size();
    for(int i=0;i<sz;i++){
        curr*=10;
        curr+=num[i]-48;
    }
    return curr;
}

vector<int> luckyNumbers;

int main(){
    fastInputOutput();
    string n;cin>>n;
    int iv = strToInt(n);
    for(int mask=0;mask<(1<<getSize(n));mask++){
        string curr = "";
        for(int i=0;i<getSize(n);i++){
            if((mask>>i)&1){
                curr+="4";
            }else{
                curr+="7";
            }
        }
        luckyNumbers.push_back(strToInt(curr));
    }
    sort(luckyNumbers.begin(), luckyNumbers.end());
    int prv = 0;
    for(int i=1;i<getSize(n);i++){
        prv += pow(2, i);
    }
    for(int i=0;i<getSize(luckyNumbers);i++){
        if(luckyNumbers[i] == iv){
            cout<<i+prv+1<<endl;
        }
    }
    return 0;
}

