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

int arr[105];
int main(){
    fastInputOutput();
    int n, pos;cin>>n>>pos;
    int total = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            total++;
        }
    }
    int addition = 1;
    int loc1 = pos+addition, loc2 = pos-addition;
    while(loc1 <= n || loc2 >= 1){
        if(loc1 <= n && loc2 >= 1){
            int sum = arr[loc1] + arr[loc2];
            if(sum == 1){
                total--;
            }
        }
        addition++;
        loc1 = pos+addition, loc2 = pos-addition;
    }
    cout<<total<<endl;
    return 0;
}

