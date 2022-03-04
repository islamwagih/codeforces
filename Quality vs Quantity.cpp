#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (ll)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 5e3+9;
const int inf = 1e7+5;
const int M = 2*N;
const int mod = 1e9+7;

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
       int n;cin>>n;
       vector<int> arr(n);
       ll sumRed = 0, sumBlue = 0;
       for(int& i:arr) cin>>i;
       sort(arr.begin(), arr.end());
       sumRed += arr[n-1];
       sumBlue += arr[0]+arr[1];
       int i = 2, j = n-2;
       while(sumBlue >= sumRed && i < j){
            sumRed += arr[j];
            sumBlue += arr[i];
            j--;
            i++;
       }
       if(sumBlue >= sumRed){
            cout<<"NO\n";
       }else{
           cout<<"YES\n";
       }
    }
    return 0;
}
