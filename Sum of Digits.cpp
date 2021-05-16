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

int main(){
    fastInputOutput();
    string a;cin>>a;
    int spells = 0, sum = 0;
    if(getSize(a) == 1){cout<<0<<endl;return 0;}
    for(int i=0;i<getSize(a);i++){
        sum += (a[i]-48);
    }
    spells++;
    while(sum >= 10){
        int newSum = 0;
        while(sum){
            newSum += sum%10;
            sum/=10;
        }
        sum = newSum;
        spells++;
    }
    cout<<spells<<endl;
    return 0;
}
 
