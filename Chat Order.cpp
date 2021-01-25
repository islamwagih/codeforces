#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}



int main(){

    fastInputOutput();
    int n;cin>>n;
    vector<string> chat(n);
    unordered_set<string> helper;
    for(int i=0;i<n;i++){
        cin>>chat[i];
    }
    for(int i=n-1;i>-1;i--){
        string curr = chat[i];
        if(helper.find(curr) == helper.end()){
            ///not found
            helper.insert(curr);
            cout<<curr<<endl;
        }
    }

    return 0;
}

