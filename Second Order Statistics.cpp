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
    set<int> secondOrder;
    for(int i=0;i<n;i++){
        int value;cin>>value;
        secondOrder.insert(value);
    }
    auto it = secondOrder.begin();
    if(secondOrder.size() == 1){
        cout<<"NO"<<endl;
    }else{
        it++;
        cout<<*it<<endl;
    }
    return 0;
}

