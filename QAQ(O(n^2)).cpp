///O(n^2)
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int strSize = s.size();
    int qaq = 0;
    for(int i=0;i<strSize;i++){
        if(s[i] != 'A'){
            continue;
        }
        int bf = 0, af = 0;
        for(int j=0;j<i;j++){
            if(s[j] == 'Q'){
                bf++;
            }
        }
        for(int j=i+1;j<strSize;j++){
            if(s[j] == 'Q'){
                af++;
            }
        }
        qaq += bf*af;
    }
    cout<<qaq<<endl;
    return 0;
}

