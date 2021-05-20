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
    int q;cin>>q;
    while(q--){
        ll num;cin>>num;
        int minOps = 0;
        if(num == 1){
            cout<<0<<endl;
            continue;
        }
        if(num == 2){
            cout<<1<<endl;
            continue;
        }
        bool badOdd = 0;
        while(num != 1){
            if(num%5 == 0){
                num*=4;
                num/=5;
            }else if(num%3 == 0){
                num*=2;
                num/=3;
            }else if(num%2 == 0){
                num/=2;
            }else{
                badOdd = 1;
                break;
            }
            minOps++;
        }
        if(!badOdd){
            cout<<minOps<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
