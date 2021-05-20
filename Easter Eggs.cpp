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
    char eggs[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    int n;cin>>n;
    string sequence = "";
    int colorInd = 0;
    for(int i=0;i<n-3;i++){
        sequence += eggs[colorInd%4];
        colorInd++;
    }
    for(int i=4;i<7;i++){
        sequence += eggs[i];
    }
    cout<<sequence<<endl;
    return 0;
}

