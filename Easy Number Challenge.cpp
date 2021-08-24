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

const int N = (1e6)+5;
int dp[N];

int solve(int n){
    if(dp[n]){
        return dp[n];
    }
    int res = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            int other = n/i;
            if(other == i){
                res++;
            }else{
                res+=2;
            }
        }
    }
    dp[n] = res;
    return dp[n];
}

int main(){

    fastInputOutput();
    int a, b,c;cin>>a>>b>>c;

    ll sum = 0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                int num = i*j*k;
                sum += solve(num);
                if(sum > 1073741824){
                    sum -= 1073741824;
                }
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}
