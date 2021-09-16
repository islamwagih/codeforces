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


int main(){

    fastInputOutput();
    int t, limit = 998244353;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string num = "";
        while(num.size() < limit && n > 1){
            num += "1";
            n-=2;
        }
        int sz = num.size();
        for(int i=0;i<sz;i++){
            if(num[i] == '1' && n >= 4){
                num[i] = '9';
                n -= 4;
            }
        }
        for(int i=0;i<sz;i++){
            if(num[i] == '1' && n >= 1){
                num[i] = '7';
                n--;
            }
        }
        cout<<num<<endl;
    }


    return 0;

}
