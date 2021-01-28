#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
 
inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
 
bool isPrime(int x){
    if(x < 2 || x%2 == 0){
        return false;
    }
    if(x == 2){
        return true;
    }
    for(int i=3;i*i<=x;i+=1){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
 
int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    for(int i=n+1;i<m;i++){
        if(isPrime(i)){
            cout<<"NO\n";
            return 0;
        }
    }
    if(isPrime(m)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
