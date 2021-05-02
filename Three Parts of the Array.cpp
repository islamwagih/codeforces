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
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left = 0, right = n-1;
    ll intersection = 0, leftSum = 0, rightSum = 0;
    while(left <= right){
        if(leftSum > rightSum){
            rightSum += arr[right--];
        }else if(rightSum > leftSum){
            leftSum += arr[left++];
        }else{
            intersection = max(intersection, leftSum);
            leftSum += arr[left++];
        }
    }
    if(leftSum == rightSum){
        intersection = max(intersection, leftSum);
    }
    cout<<intersection<<endl;
    return 0;
}
