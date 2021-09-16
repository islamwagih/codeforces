#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
char matrix[9][9];
int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++){
                cin>>matrix[i][k];
                if(matrix[i][k] == '4') matrix[i][k] = '5';
            }
        }
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++){
                cout<<matrix[i][k];
            }
            cout<<endl;
        }
    }


    return 0;
}
