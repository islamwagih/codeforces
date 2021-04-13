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
    int n, m;cin>>n>>m;
    double* arr = new double[n];
    for(int i=0;i<n;i++){
        double a, b;cin>>a>>b;
        arr[i] = a/b;
    }
    double* minCost = min_element(arr, arr+n);
    cout<<setprecision(9)<<*minCost*m<<endl;
    return 0;
}
