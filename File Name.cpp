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
    string file;cin>>file;
    int toRmv = 0, i = 0;
    while(i < (n-1)){
        if(file[i] == 'x' && file[i+1] == 'x'){
            int j = i+2;
            while(j < n && file[j] == 'x'){
                toRmv++;
                j++;
            }
            i = j;
        }else{
            i++;
        }
    }
    cout<<toRmv<<endl;
    return 0;
}
