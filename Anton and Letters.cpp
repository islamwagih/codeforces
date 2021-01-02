#include <iostream>
using namespace std;
int main(){
    string dict;getline(cin, dict);
    int letters[26] = {0};///to save letters a-b-c-...-z each letter would be indexed in letter-'a' and each index
                          ///will have how many times this letter appear
    int dictSize = dict.size();
    for(int i=0;i<dictSize;i++){
        int idx = dict[i]-'a';
        if(idx < 26 && idx > -1){
            letters[idx]++;
        }
    }
    int disLetters = 0;
    for(int i=0;i<26;i++){
        if(letters[i] != 0){
            disLetters++;
        }
    }
    cout<<disLetters<<endl;
    return 0;
}
