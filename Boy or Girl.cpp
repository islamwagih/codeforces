#include <bits/stdc++.h>
using namespace std;
 
bool inVec(vector<int>& v,char s){
    for(int i=0;i<v.size();i++){
        if(s == v[i]){
            return true;
        }
    }
    return false;
}
 
int main(){
    string str;cin>>str;
    int dc = 0;
    vector<int> chars;
    for(int i=0;i<str.size();i++){
        if(!inVec(chars, str[i])){
            dc++;
            chars.push_back(str[i]);
        }
    }
    if(dc%2 == 0){
        cout<<"CHAT WITH HER!\n";
    }else{
        cout<<"IGNORE HIM!\n";
    }
    return 0;
}
