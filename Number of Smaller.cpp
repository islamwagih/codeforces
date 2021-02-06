///time complexity is O(n+m)
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
    int* firstArr = new int[n];
    int* secArr = new int[m];

    for(int i=0;i<n;i++){
        cin>>firstArr[i];
    }

    for(int i=0;i<m;i++){
        cin>>secArr[i];
    }

    int total = 0, p1 = 0;
    for(int i=0;i<m;i++){
        int increment = 0;
        for(int j = p1;j<n;j++){
            if(firstArr[j] < secArr[i]){
                total++, increment++;
            }else{
                break;
            }
        }
        p1 += increment;
        cout<<total<<' ';
    }

    return 0;
}
