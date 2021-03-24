#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, r, a;
    cin>>l>>r>>a;
    if(l == r){
        cout<<(r + a/2)*2<<endl;
    }else{
        int target = min(l, r) + a;
        if(target < max(l, r)){
            cout<<target*2<<endl;
        }else{
            int bonus = abs(l-r);
            a -= bonus;
            target = max(l, r) + a/2;
            cout<<target*2<<endl;
        }
    }
    return 0;
}

