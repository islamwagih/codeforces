#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
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

    int n;cin>>n;
    int* arr = new int[n];
    bool hasSol = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == 1){
            hasSol = 1;
        }
    }

    if(!hasSol){
        cout<<0<<endl;
        return 0;
    }

    ll ans = 1, i = 0;
    while(i < n){
        int next = -1;
        if(arr[i] == 1){
            int j = i+1;
            while(j < n){
                if(arr[j] == 1){
                    ans *= j-i;
                    next = j;
                    break;
                }
                j++;
            }
        }
        if(next != -1){
            i = next;
        }else{
            i++;
        }
    }
    cout<<ans<<endl;
    delete[] arr;


    return 0;
}
