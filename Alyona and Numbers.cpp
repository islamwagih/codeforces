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

///we will loop until the minimum of n, m
///to get all pairs which are their sum%5 == 0 we need to loop all over the range of numbers of min(n, m)
///for example if we have 6 and 12 then if the current number is X which is within the range[1, 6] then X + max(6, 12) = Y
///so how many 5s in Y the answer will be integer division of Y/5 which is Z.
///then we should subtract the answer which is Z pairs, from integer division of X/5 and
///we should not consider such pairs because it's previously calculated
///to get the total number we just keep adding the answer of each number

int main(){

    fastInputOutput();
    int n, m;cin>>n>>m;
    ull total = 0;
    int mn = min(n, m), mx = max(n, m);

    for(int i=1;i<=mn;i++){
        total += (((i+mx)/5) - (i/5));
    }

    cout<<total<<endl;

    return 0;
}
