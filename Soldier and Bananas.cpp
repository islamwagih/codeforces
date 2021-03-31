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
    int k,n,w;cin>>k>>n>>w;
    int totalCost = (w*(w+1))/2;
    totalCost*=k;
    if(n >= totalCost){
        cout<<0<<endl;
    }else{
        cout<<totalCost-n<<endl;
    }
    return 0;
}
 
