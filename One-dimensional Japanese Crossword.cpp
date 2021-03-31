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
    char* arr = new char[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> encryption;
    int sz = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 'B'){
            sz++;
        }
        if(arr[i] == 'W' && sz != 0){
            encryption.push_back(sz);
            sz = 0;
        }
    }
    if(sz != 0){
        encryption.push_back(sz);
    }
    cout<<encryption.size()<<endl;
    for(int x:encryption){
        cout<<x<<' ';
    }
    return 0;
}

