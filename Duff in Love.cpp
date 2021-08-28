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

bool isLovely(ll num){
    for(ll a = 2;a*a<=num;a++){
        if(num%(a*a) == 0){
            return false;
        }
    }
    return true;
}

void fillDivs(set<ll>& toFill, ll num){
    toFill.insert(1);
    for(ll a=2;a*a<=num;a++){
        if(num%a == 0){
            toFill.insert(a);
            if(a*a != num)
                toFill.insert(num/a);
        }
    }
    toFill.insert(num);
}

int main(){

    fastInputOutput();
    ll n;cin>>n;
    set<ll> divisors;
    fillDivs(divisors, n);
    auto it = divisors.rbegin();
    while(it != divisors.rend()){
        if(isLovely(*it)){
            cout<<*it<<endl;
            break;
        }
        it++;
    }

    return 0;
}
