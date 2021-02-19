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
    string binary;cin>>binary;
    int oldOnes = 0, totalMissed = 0, turns = 0;
    for(int i=binary.size()-1;i>-1;i--){
        if(turns%2 == 0){
            if(i == 0 && oldOnes == 0){
                break;
            }
            totalMissed++;
        }
        turns++;
        oldOnes += ((binary[i] == '1') ? 1:0);
    }
    cout<<totalMissed<<endl;

    return 0;
}

