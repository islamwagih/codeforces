#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;

int main(){
    fastInputOutput();
    set<int> unUsedPerms;
    int n;cin>>n;
    vector<int> perm(n, -1);
    for(int i=1;i<=n;i++) unUsedPerms.insert(i);
    int matrix[55][55];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>matrix[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            int val = matrix[i][j];//belongs to perm[i] or perm[j]
            bool belongToi = 1;
            if(unUsedPerms.find(val) == unUsedPerms.end()) continue;
            for(int k=0;k<n;k++){
                if(k == i || k == j) continue;
                if(matrix[j][k] == val){
                    //belongs to j
                    perm[j] = val;
                    belongToi = 0;
                    break;
                }
            }
            if(belongToi) perm[i] = val;
            unUsedPerms.erase(val);
        }
    }
    for(int i=0;i<n;i++){
        if(perm[i] == -1){
            perm[i] = *unUsedPerms.begin();
            unUsedPerms.erase(perm[i]);
        }
        cout<<perm[i]<<' ';
    }

    return 0;
}
