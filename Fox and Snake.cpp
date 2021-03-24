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
    int n, m, k = 0;cin>>n>>m;
    for(int i=0;i<n;i++){
        bool inner = false;
        for(int j=0;j<m;j++){
            if(i%2 == 0){
                cout<<'#';
                inner = true;
            }else{
                if(j == 0 && k%2){
                    cout<<'#';
                }else if(j == m-1 && k%2 == 0){
                    cout<<'#';
                }else{
                    cout<<'.';
                }
            }
        }
        if(!inner)
            k++;
        cout<<endl;
    }
    return 0;
}
 
