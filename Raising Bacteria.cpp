#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bool isPowerOf2(int n){
    if(n < 1){
        return false;
    }
    return (n & (n-1)) == 0;
}

int solve(int x){
    if(isPowerOf2(x)){
        return 1;
    }
    int total = 0;
    while(x){
        bool test = x%2;
        if(test != 0){
            total++;
        }
        x /= 2;
    }
    return total;
}

int main(){

    fastInputOutput();
    int x;cin>>x;
    cout<<solve(x)<<endl;

    return 0;
}

