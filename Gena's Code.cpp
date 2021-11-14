#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5+5;
const int inf = 1e9+5;
const int M = 2*N;


bool isBea(string& curr){
    bool visOne = 0;
    for(char c:curr){
        if(c != '0' && c != '1') return false;
        if(c == '1' && visOne) return false;
        if(c == '1'){
            visOne = 1;
        }
    }
    return true;
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    string notBea = "";
    int zeroCnt = 0;
    bool zeroCase = 0;
    for(int i=0;i<n;i++){
        string curr;cin>>curr;
        if(curr == "0"){
            zeroCase = 1;
        }else if(isBea(curr)){
            zeroCnt += count(curr.begin(), curr.end(), '0');
        }else{
            notBea = curr;
        }
    }
    if(zeroCase){
        cout<<0<<endl;
    }else if(notBea == ""){
        ///all is beautiful
        cout<<1;
        for(int i=0;i<zeroCnt;i++) cout<<0; cout<<endl;
    }else{
         cout<<notBea;
         for(int i=0;i<zeroCnt;i++) cout<<0; cout<<endl;
    }
    return 0;
}
