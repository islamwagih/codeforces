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

const int N = 105;
set<char> questions[N];

void putAns(set<char>& s, char ans){
   s.clear();
   s.insert(ans);
}

void fillPos(set<char>& s){
    for(char curr = 'A';curr<='D';curr++){
        s.insert(curr);
    }
}

int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){

        for(int i=0;i<N;i++){
            questions[i].clear();
        }

        int q, m;cin>>q>>m;

        for(int i=0;i<q;i++){
            fillPos(questions[i]);
        }

        while(m--){
            for(int i=0;i<q;i++){
                char que, state;cin>>que>>state;
                if(questions[i].size() > 1){
                    if(state == 'T'){
                        putAns(questions[i], que);
                    }else{
                        if(questions[i].find(que) != questions[i].end()) questions[i].erase(que);
                    }
                }
            }
        }

        for(int i=0;i<q;i++){
            if(questions[i].size() == 1){
                char ans = *questions[i].begin();
                cout<<ans;
            }else{
                cout<<'?';
            }
            if(i+1 < q) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
