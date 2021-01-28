#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
 
inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
 
int main(){
    fastInputOutput();
    int n, total = 0;
    cin>>n;
    while(n--){
        string shape;cin>>shape;
        if(shape == "Tetrahedron"){
            total += 4;
        }else if(shape == "Cube"){
            total += 6;
        }else if(shape == "Octahedron"){
            total += 8;
        }else if(shape == "Dodecahedron"){
            total += 12;
        }else{
            total += 20;
        }
    }
    cout<<total<<endl;
    return 0;
}
