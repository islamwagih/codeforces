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

const int N = 1e5+5;
const int inf = 1e9+5;
const int M = 2*N;

int n, m;
bool A[105][105], C[105][105], B[105][105];


int main(){
    fastInputOutput();
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            C[i][k] = A[i][k] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>B[i][k];
            if(B[i][k] == 0){
                for(int x=0;x<m;x++){
                    A[i][x] = C[i][x] = 0;
                }
                for(int x=0;x<n;x++){
                    A[x][k] = C[x][k] = 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]){
                for(int x=0;x<m;x++) C[i][x] = 1;
                for(int x=0;x<n;x++) C[x][j] = 1;
            }
        }
    }

    bool eq = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(C[i][j] != B[i][j]){
                eq = 0;
                break;
            }
        }
    }

    if(eq){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<A[i][j]<<' ';
            }
            cout<<endl;
        }
    }else{
        cout<<"NO\n";
    }


    return 0;
}
