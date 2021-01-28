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
    int n, k;cin>>n>>k;
    set<int> kDigits, currDigits;
    int* arr = new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<=k;i++){
        kDigits.insert(i);
    }

    int total = 0;
    for(int i=0;i<n;i++){
        int curr = arr[i];
        bool noIncrement = 0;
        while(curr){
            currDigits.insert(curr%10);
            curr/=10;
        }
        for(auto k:kDigits){
            if(currDigits.find(k) == currDigits.end()){
                 noIncrement = 1;
                 break;
            }
        }
        if(!noIncrement)
            total++;
        currDigits.clear();
    }

    cout<<total<<endl;
    return 0;
}

