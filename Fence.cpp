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
    int n, k;cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ///assume first k is the minimum then compute from k to n for each k sub array
    int currMinSum = 0, minSum = 0, ind = 0, l = 0;
    for(int i=0;i<k;i++){
        currMinSum += arr[i];
    }
    minSum = currMinSum;
    for(int r=k;r<n;r++){
        currMinSum+=arr[r];
        currMinSum-=arr[l];
        if(currMinSum < minSum){
            minSum = currMinSum;
            ind = l+1;
        }
        l++;
    }
    cout<<ind+1<<endl;
    return 0;
}

