///O(n)
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int strSize = s.size();
    int qaq = 0, bf = 0, af = 0, tq = 0;
    for(int i=0;i<strSize;i++){
        if(s[i] == 'Q'){
            tq++;
        }
    }
    for(int i=0;i<strSize;i++){
        if(s[i] == 'A'){
            af = tq-bf;
            qaq += bf*af;
            bf = 0;
        }
        if(s[i] == 'Q'){
            bf++;
        }
    }
    cout<<qaq<<endl;
    return 0;
}

