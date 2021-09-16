#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        priority_queue<int> cards;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            cards.push(val);
        }
        bool turn = 1;
        ll alice = 0, bob = 0;
        while(!cards.empty()){
            int top = cards.top();
            if(top%2 && !turn) bob+=top;
            if(top%2 == 0 && turn) alice+=top;
            cards.pop();
            turn = !turn;
        }

        string result = "Tie";
        if(alice > bob) result = "Alice";
        if(bob > alice) result = "Bob";
        cout<<result<<endl;
    }

    return 0;

}
