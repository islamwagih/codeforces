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
    ///O(N^4) Time, O(1) Space
    int r1, r2, c1, c2, d1, d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    set<int> length;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                for(int m=1;m<=9;m++){
                    if(i+j == r1 && k+m == r2 && i+m == d1 && j+k == d2 && i+k == c1 && j+m == c2){
                        length.insert(i);
                        length.insert(j);
                        length.insert(k);
                        length.insert(m);
                        if(length.size() == 4){
                            cout<<i<<' '<<j<<'\n'<<k<<' '<<m<<endl;
                            return 0;
                        }else{
                            length.clear();
                        }
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}


