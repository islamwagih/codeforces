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

int main(){

    fastInputOutput();

    int freq[5] = {0};
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        freq[val]++;
    }

    int ans = freq[4];
    ans += freq[3];
    int remainingOfThree = freq[3]*4 - freq[3]*3;
    freq[1] -= remainingOfThree;

    int twoTaxies = ceil((freq[2]*2)/4.0);
    ans += twoTaxies;
    int remainingOfTwo = twoTaxies*4 - freq[2]*2;
    freq[1] -= remainingOfTwo;

    if(freq[1] > 0){
        ans += ceil(freq[1]/4.0);
    }

    cout<<ans<<endl;

    return 0;
}
