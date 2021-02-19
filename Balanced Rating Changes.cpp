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
    int n;cin>>n;
    int *arr = new int[n],*ans = new int[n], sum = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i]/2;
        ans[i] = arr[i]/2;
    }

    for(int i=0;i<n;i++){
        if(sum == 0){
            break;
        }else{
            if(arr[i]%2 != 0){
                if(arr[i] > 0){
                    ans[i]++;
                    sum++;
                }else{
                    ans[i]--;
                    sum--;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}

