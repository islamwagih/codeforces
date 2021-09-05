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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string enemy, gregor;
        cin>>enemy>>gregor;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(gregor[i] == '0') continue;
            bool op1 = (i+1 < n && enemy[i+1] == '1') ? 1:0;
            bool op2 = (enemy[i] == '0') ? 1:0;
            bool op3 = (i-1 < n && enemy[i-1] == '1') ? 1:0;
            if(op1){
                ans++;
                gregor[i] = '0';
                enemy[i+1] = '2';
            }else if(op2){
                ans++;
                gregor[i] = '0';
                enemy[i] = '2';
            }else if(op3){
                ans++;
                gregor[i] = '0';
                enemy[i-1] = '2';
            }
        }
        cout<<ans<<endl;
    }

    return 0;

}
