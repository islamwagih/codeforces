#include <bits/stdc++.h>
using namespace std;

string rev(string toRev){
    string ret = "";
    int lastInd = toRev.size();
    while(lastInd){
        ret += toRev[lastInd-1];
        lastInd--;
    }
    return ret;
}

int main(){

    string a, b;cin>>a>>b;
    string revrsed = rev(a);
    cout<<((revrsed == b) ? "YES":"NO")<<endl;

    return 0;
}
 
