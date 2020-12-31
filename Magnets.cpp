#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, groups = 1;cin>>n;
    string oldMagnet = "", currMagnet = "";
    while(n--){
        cin>>currMagnet;
        if(oldMagnet != ""){
            if(oldMagnet[1] == currMagnet[0]){
                groups++;
            }
        }
        oldMagnet = currMagnet;
    }
    cout<<groups<<endl;
    return 0;
}
