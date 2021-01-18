///O(n^3)
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int strSize = s.size();
    int qaq = 0;
    for(int i=0;i<strSize;i++){
        for(int j=i+1;j<strSize;j++){
            for(int k=j+1;k<strSize;k++){
                if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q'){
                    qaq++;
                }
            }
        }
    }
    cout<<qaq<<endl;
    return 0;
}

