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
    int n, m, k;cin>>n>>m>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lptr = -1, rptr = -1;
    ///get the nearest from left
    for(int i=0;i<m;i++){
        if(arr[i] == 0){continue;}
        if(arr[i] <= k){
            lptr = i;
        }
    }
    ///get the nearest from right
    for(int i=m;i<n;i++){
        if(arr[i] == 0){continue;}
        if(arr[i] <= k){
            rptr = i;
            break;
        }
    }
    if(lptr == -1){
        rptr++;
        int diff = abs(rptr-m);
        cout<<diff*10<<endl;
    }else if(rptr == -1){
        lptr++;
        int diff = abs(m-lptr);
        cout<<diff*10<<endl;
    }else{
        lptr++, rptr++;
        int first = abs(rptr-m)*10, second = abs(lptr-m)*10;
        cout<<min(first, second)<<endl;
    }
    return 0;
}
