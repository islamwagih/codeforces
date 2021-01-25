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
    int n;cin>>n;
    map<string, string> parentToLastChild, childToParent;

    for(int i=0;i<n;i++){
        string oldHandle, newHandle;
        cin>>oldHandle>>newHandle;
        auto it = childToParent.find(oldHandle);
        if(it == childToParent.end()){
            parentToLastChild[oldHandle] = newHandle;
            childToParent[newHandle] = oldHandle;
        }else{
            parentToLastChild[it->second] = newHandle;
            childToParent[newHandle] = it->second;
        }
    }

    cout<<parentToLastChild.size()<<endl;
    for(auto it:parentToLastChild){
        cout<<it.first<<' '<<it.second<<endl;
    }

    return 0;
}

