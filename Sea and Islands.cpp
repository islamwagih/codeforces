#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
//multi indexedSet -> less_equal<int>/greater_equal<int>
//indexedSet -> less<int>/greater<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
*/

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 2e2+5;
const int inf = 1e9;


int main(){

    fastInputOutput();
    int n, k;cin>>n>>k;
    char matrix[101][101];
    int currLand = 0;
    bool land = 1;
    for(int i=0;i<n;i++){
        land = i%2 == 0;
        for(int k=0;k<n;k++){
            if(land) matrix[i][k] = 'L', currLand++;
            else matrix[i][k] = 'S';
            land = !land;
        }
    }
    if(currLand < k){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        int diff = currLand - k;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(diff && matrix[i][j] == 'L'){
                    matrix[i][j] = 'S';
                    diff--;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
