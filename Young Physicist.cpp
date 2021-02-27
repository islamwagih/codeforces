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

    //fastInputOutput();
    int n;cin>>n;
    int* forces = new int[3];

    for(int i=0;i<3;i++){
        forces[i] = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int val;cin>>val;
            forces[j]+=val;
        }
    }

    bool idle = true;
    for(int i=0;i<3;i++){
        if(forces[i] != 0){
            idle = false;
            break;
        }
    }

    cout<<((idle == true) ? "YES":"NO")<<endl;
    return 0;
}
 
