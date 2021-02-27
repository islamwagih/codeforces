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

    //fastInputOutput();
    int n;cin>>n;
    int x = 0;
    string statement;
    while(n--){
        cin>>statement;
        if(statement == "++X" || statement == "X++"){
            x++;
        }else{
            x--;
        }
    }
    cout<<x<<endl;
    return 0;
}

