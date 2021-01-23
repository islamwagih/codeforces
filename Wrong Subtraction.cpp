#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n,k;cin>>n>>k;
    for(int i=0;i<k;i++){
        n = (n%10 == 0)?n/=10:n-=1;
    }
    cout<<n<<endl;
    return 0;
}
