#include <bits/stdc++.h>
using namespace std;
int main(){
    string word;cin>>word;
    int nl = 0, nu = 0;
    for(int i=0;i<word.size();i++){
        if(word[i] <= 90){
            nu++;
        }else{
            nl++;
        }
    }
    if(nl >= nu){
        for(int i=0;i<word.size();i++){
            if(word[i] <= 90){
                word[i]+=32;
            }
        }
    }else{
        for(int i=0;i<word.size();i++){
            if(word[i] > 90){
                word[i]-=32;
            }
        }
    }
    cout<<word<<endl;
    return 0;
}
