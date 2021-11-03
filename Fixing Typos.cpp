#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5+2;
const int inf = 2e9+1;
const int M = 2*N;


int main(){
    fastInputOutput();
    string word;cin>>word;
    string newWord = "";
    int sz = word.size();
    for(int i=0;i<sz;i++){
        int j = i;
        while(j < sz && word[i] == word[j+1]) j++;
        if(j - i + 1 > 2){
            newWord += word[i];
            newWord += word[i];
            i = j;
        }else newWord += word[i];
    }

    sz = newWord.size();
    vector<bool> bits(sz, 1);
    for(int i=0;i<sz-1;i++){
        if(bits[i] == 0) continue;
        if(newWord[i] == newWord[i+1]){
            int start = i+2;
            if(start+1 < sz && newWord[start] == newWord[start+1]) bits[start] = 0;
        }
    }
    for(int i=0;i<newWord.size();i++){
        if(bits[i]) cout<<newWord[i];
    }

    return 0;
}
