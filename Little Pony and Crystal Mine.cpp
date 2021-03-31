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

void diamond(int n){
    int numOfD = 1, numOfAst = n-1;
    ///print the upper bound
    for(int i=0;i<n/2;i++){
        for(int k=0;k<numOfAst/2;k++){
            cout<<'*';
        }
        for(int k=0;k<numOfD;k++){
            cout<<'D';
        }
        for(int k=0;k<numOfAst/2;k++){
            cout<<'*';
        }
        cout<<endl;
        numOfD += 2;
        numOfAst -= 2;
    }

    ///print only d
    for(int i=0;i<n;i++){
        cout<<'D';
    }
    cout<<endl;
    ///print the lower bound
    numOfD = n-2, numOfAst = 2;
    for(int i=0;i<n/2;i++){
        for(int k=0;k<numOfAst/2;k++){
            cout<<'*';
        }
        for(int k=0;k<numOfD;k++){
            cout<<'D';
        }
        for(int k=0;k<numOfAst/2;k++){
            cout<<'*';
        }
        cout<<endl;
        numOfD -= 2;
        numOfAst += 2;
    }

}

int main(){
    int n;cin>>n;
    diamond(n);
    return 0;
}

