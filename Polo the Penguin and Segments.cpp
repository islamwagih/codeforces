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

int covered(pair<int, int> segment){
    return segment.second - segment.first + 1;
}

int main(){

    fastInputOutput();
    int n, k, total = 0;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        pair<int, int> temp;
        cin>>temp.first>>temp.second;
        total += covered(temp);
    }

    cout<<((k - (total%k))%k)<<endl;

    return 0;
}

