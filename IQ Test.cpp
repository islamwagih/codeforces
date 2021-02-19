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

int covered(pair<int, int> segment){
    return segment.second - segment.first + 1;
}

int main(){

    fastInputOutput();
    char matrix[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=1;j<4;j++){
            char curr = matrix[i][j], prev = matrix[i][j-1];
            if(curr == prev && (matrix[i+1][j] == curr || matrix[i+1][j-1] == curr)){
                cout<<"YES\n";
                return 0;
            }
            if(curr != prev){
                char third = matrix[i+1][j], fourth = matrix[i+1][j-1];
                if(third == fourth){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
 
