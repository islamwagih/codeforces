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

bool isPrime(int n){
    if(n == 2){
        return 1;
    }
    if(n < 2 || n%2 == 0){
        return 0;
    }
    int sqrtN = sqrt(n);
    for(int i=2;i<=sqrtN;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}


int main(){
    fastInputOutput();
    int n;cin>>n;
    int first = 2;
    int second = n-first;
    if(isPrime(second)){
        cout<<first<<' '<<second<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}

