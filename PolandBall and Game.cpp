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
    int x,y;cin>>x>>y;
    set<string> poland, enemy;
    int mutual = 0;
    for(int i=0;i<x;i++){
        string curr;cin>>curr;
        poland.insert(curr);
    }
    for(int i=0;i<y;i++){
        string curr;cin>>curr;
        if(poland.find(curr) == poland.end()){
            ///unique word to enemy
            enemy.insert(curr);
        }else{
            mutual++;
        }
    }
    int polandUnique = poland.size() - mutual, enemyUnique = enemy.size();
    if(polandUnique > enemyUnique){
        cout<<"YES\n";
    }else if(enemyUnique > polandUnique){
        cout<<"NO\n";
    }else{
        ///we have two cases if the mutual words are odd then poland will win, if even enemy will win. (because poland always starts the game)
        cout<<(mutual%2 == 0 ? "NO":"YES")<<endl;
    }
    return 0;
}

