#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n,x,y;cin>>n>>x>>y;
    int smallAns = min(x, y);n--;
    int low = 0, high = 2e9, mid = (low+high)/2;
    while(low < high){
        int copied = (mid/x)+(mid/y);
        if(copied >= n){
            high = mid;
        }else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    cout<<smallAns+mid<<endl;
    return 0;
}

