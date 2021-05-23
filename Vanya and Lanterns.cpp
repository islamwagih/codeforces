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
    int n,l;cin>>n>>l;
    int* lanterna = new int[n];
    for(int i=0;i<n;i++){
        cin>>lanterna[i];
    }
    sort(lanterna, lanterna+n);
    double maxRadius = -1;
    for(int i=0;i<n-1;i++){
        maxRadius = max(maxRadius, (lanterna[i+1]-lanterna[i])/2.0);
    }
    maxRadius = max(max(maxRadius, (double)abs(0-lanterna[0])), max(maxRadius, (double)abs(lanterna[n-1]-l)));
    cout<<fixed<<setprecision(10)<<maxRadius<<endl;
    delete[] lanterna;
    return 0;
}
 
