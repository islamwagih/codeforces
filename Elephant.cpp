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
    int x;cin>>x;
    int steps[5] = {1, 2, 3, 4, 5};
    int idx = 4, minimumSteps = 0;
    while(x){
        if((x-steps[idx]) >= 0){
            x -= steps[idx];
            minimumSteps++;
        }else{
            idx--;
        }
    }
    cout<<minimumSteps<<endl;
    return 0;
}

