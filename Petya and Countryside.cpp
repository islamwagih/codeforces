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
    int n, maximum = 0;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int curr = arr[i], cnt = 1;
        for(int j=i+1;j<n;j++){
            if(arr[j] <= curr){
                cnt++;
                curr = arr[j];
            }else{
                break;
            }
        }
        curr = arr[i];
        for(int j=i-1;j>-1;j--){
            if(arr[j] <= curr){
                cnt++;
                curr = arr[j];
            }else{
                break;
            }
        }
        maximum = max(maximum, cnt);
    }
    int curr = arr[n-1], cnt = 1;
    for(int i=n-2;i>-1;i--){
        if(arr[i] <= curr){
            cnt++;
            curr = arr[i];
        }else{
            break;
        }
    }
    cout<<max(maximum, cnt)<<endl;
    delete[] arr;
    return 0;
}

