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
    int s, n;cin>>s>>n;
    multimap<int, int> dragons;
    bool gameOver = 0;
    for(int i=0;i<n;i++){
        int x, y;cin>>x>>y;
        dragons.insert({x, y});
    }
    for(auto it:dragons){
        if(s > it.first){
            s += it.second;
        }else{
            gameOver = 1;
            break;
        }
    }
    cout<<(gameOver == 0 ? "YES":"NO")<<endl;
    return 0;
}

