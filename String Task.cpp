#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

string filter(string str){
    string ret;
    int maxSize = str.size();
    for(int i=0;i<maxSize;i++){
        if(!isVowel(str[i])){
            ret += '.';
            ret += tolower(str[i]);
        }
    }
    return ret;
}

int main(){

    string input;cin>>input;
    string output = filter(input);
    cout<<output<<endl;

    return 0;
}

