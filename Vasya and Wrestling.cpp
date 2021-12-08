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

int main(){
    fastInputOutput();
    vector<int> first, sec;
    ll firstSum=0, secSum=0;
    int n;cin>>n;
    int lastVal = 0;
    while(n--){
        int xi;cin>>xi;
        if(xi > 0){
            first.push_back(xi);
            firstSum += xi;
        }else{
            sec.push_back(-xi);
            secSum += -xi;
        }
        lastVal = xi;
    }

    if(firstSum > secSum){
        cout<<"first\n";
        return 0;
    }
    if(secSum > firstSum){
        cout<<"second\n";
        return 0;
    }

    ///check lexicographically order
    int sz = min(first.size(), sec.size());
    for(int i=0;i<sz;i++){
        if(first[i] > sec[i]){
            cout<<"first\n";
            return 0;
        }
        if(sec[i] > first[i]){
            cout<<"second\n";
            return 0;
        }
    }

    ///check who is last
    cout<<(lastVal > 0 ? "first":"second")<<endl;
    return 0;
}
