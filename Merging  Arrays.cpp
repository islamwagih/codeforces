#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    int* firstSmallArr = new int[n];
    int* secSmallArr = new int[m];
    int* sortedArr = new int[n+m];

    for(int i=0;i<n;i++){
        cin>>firstSmallArr[i];
    }

    for(int i=0;i<m;i++){
        cin>>secSmallArr[i];
    }

    int p1 = 0, p2 = 0, k = 0;
    while(p1 < n || p2 < m){
        if(p2 == m || p1 < n && firstSmallArr[p1] < secSmallArr[p2]){
            sortedArr[k++] = firstSmallArr[p1++];
        }else{
            sortedArr[k++] = secSmallArr[p2++];
        }
    }

    for(int i=0;i<(n+m);i++){
        cout<<sortedArr[i]<<' ';
    }

    return 0;
}
