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
    int n, a, b;cin>>n>>a>>b;
    ///|`| a-b-a
    int currLength = n;
    if(currLength >= (2*a+b)){
        currLength -= (2*a+b);
        ///answer will be 1 or 2
        cout<<((currLength >= (2*a+b)) ? 1:2)<<endl;
    }else if(currLength >= (2*a)){
        ///answer will be 3 if currLength >= a+b or currLength >= 4*a or 4 otherwise
        if((currLength >= (a+b))){
            cout<<3<<endl;
        }
        else if((currLength >= 4*a)){
            cout<<3<<endl;
        }else{
            cout<<4<<endl;
        }
    }else if(currLength >= (a+b)){
        ///one answer -> 4
        cout<<4<<endl;
    }else{
        ///it will be 5 or 6
        cout<<((currLength >= 2*b)? 5:6)<<endl;
    }
    return 0;
}
 
