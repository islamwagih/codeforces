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
    char* encoded = new char[n];
    for(int i=0;i<n;i++){
        cin>>encoded[i];
    }
    char* decoded = new char[n];
    for(int i=0;i<n;i++){
        decoded[i] = '-';
    }
    int sz = n;
    for(int i=0;i<n;i++){
        int idx = sz/2;
        if(sz%2 == 0){
            ///even size must be on left
            idx--;
            ///we have the correct ind but decrease it until we get empty slot
            while(decoded[idx] != '-'){ idx--; }
            decoded[idx] = encoded[i];
        }else{
            ///we have the correct ind but increase it until we get empty slot
            while(decoded[idx] != '-'){ idx++; }
            decoded[idx] = encoded[i];
        }
        sz--;
    }
    for(int i=0;i<n;i++){
        cout<<decoded[i];
    }
    cout<<endl;
    delete[] encoded;
    delete[] decoded;
    return 0;
}

