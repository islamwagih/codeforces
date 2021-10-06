#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
//multi indexedSet -> less_equal<int>/greater_equal<int>
//indexedSet -> less<int>/greater<int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_set tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
*/

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int mod = 1e9+7;
const int N = 2e2+5;
const int inf = 1e9;

int frq[26];
string seq;
int calcMis(){
    int missing = 0;
    for(int i=0;i<26;i++) if(frq[i] == 0) missing++;
    return missing;
}

void putAnswer(int start){
    ///answer found
    vector<int> missedLetters(26, 1);
    for(int i=start;i<start+26;i++){
        if(seq[i] != '?'){
            missedLetters[seq[i]-'A'] = 0;
        }
    }
    vector<int> need;
    for(int i=0;i<26;i++){
        if(missedLetters[i] == 1) need.push_back(i);
    }
    int idx = 0;
    for(int i=start;i<start+26;i++){
        if(seq[i] == '?') seq[i] = need[idx]+'A', idx++;
    }
    for(char& c:seq) if(c == '?') c = 'A';
}

int main(){

    fastInputOutput();
    cin>>seq;
    int sz = seq.size();
    if(sz < 26){
        return cout<<-1<<endl, 0;
    }else{
        int qm = 0;
        for(int i=0;i<26;i++){
            if(seq[i] == '?') qm++;
            else frq[seq[i]-'A']++;
        }
        int mis = calcMis();
        if(qm == mis){
            putAnswer(0);
            return cout<<seq<<endl, 0;
        }else{
            int left = 0;
            for(int right = 26;right<sz;right++){
                if(seq[left] == '?') qm--;
                else frq[seq[left]-'A']--;
                left++;
                if(seq[right] == '?') qm++;
                else frq[seq[right]-'A']++;
                mis = calcMis();
                if(qm == mis){
                    putAnswer(left);
                    return cout<<seq<<endl, 0;
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
