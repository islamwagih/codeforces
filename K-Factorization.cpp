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

const int N = 2e5+5;

vector<int> primeFactors;
void primeFactorization(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            primeFactors.push_back(i);
            n/=i;
        }
    }
    if(n > 1) primeFactors.push_back(n);
}

int main(){

    fastInputOutput();
    int n, k;cin>>n>>k;
    primeFactorization(n);
    if(primeFactors.size() < k){
        cout<<-1<<endl;
    }else{
        int bigTerm = 1;
        while(primeFactors.size() >= k){
            bigTerm*=primeFactors.back();
            primeFactors.pop_back();
        }
        for(int prime:primeFactors) cout<<prime<<' ';
        cout<<bigTerm<<'\n';
    }

    return 0;
}
