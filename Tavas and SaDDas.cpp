#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int strToInt(string num){
    int curr = 0, sz = num.size();
    for(int i=0;i<sz;i++){
        curr*=10;
        curr+=num[i]-48;
    }
    return curr;
}

int luckyNum;
vector<int> luckyNumbers;
int getIndex(){
    int sz = luckyNumbers.size();
    for(int i=0;i<sz;i++){
        if(luckyNumbers[i] == luckyNum){
            return i;
        }
    }
}

int main(){
    fastInputOutput();
    cin>>luckyNum;
    for(int sz=1;sz<=9;sz++){
        int fours = sz, sevens = 0;
        for(int p=0;p<sz+1;p++){
            string curr = "";
            for(int i=0;i<fours;i++){
                curr += "4";
            }
            for(int i=0;i<sevens;i++){
                curr += "7";
            }
            sort(curr.begin(), curr.end());
            do{
                luckyNumbers.push_back(strToInt(curr));
            }while(next_permutation(curr.begin(), curr.end()));
            fours--, sevens++;
        }
    }
    sort(luckyNumbers.begin(), luckyNumbers.end());
    cout<<getIndex()+1<<endl;
    return 0;
}
