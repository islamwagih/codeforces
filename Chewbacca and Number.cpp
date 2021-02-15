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
    string number;cin>>number;
    for(int i=0;i<number.size();i++){
        if(number[i]-48 >= 5){
            if(i == 0 && number[i] == '9'){
                continue;
            }
            number[i] = 9-(number[i]-48)+48;
        }
    }
    cout<<number<<endl;
    return 0;
}

