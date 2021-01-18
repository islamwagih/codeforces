#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int p;cin>>p;
    unordered_set<int> players;
    for(int i=0;i<p;i++){
        int value;cin>>value;
        players.insert(value);
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int value;cin>>value;
        players.insert(value);
    }
    for(int i=1;i<=n;i++){
        auto it = players.find(i);
        if(it == players.end()){
            ///we can't pass this level
            cout<<"Oh, my keyboard!\n";
            return 0;
        }
    }
    cout<<"I become the guy.\n";
    return 0;
}

