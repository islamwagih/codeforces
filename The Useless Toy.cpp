#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


char getNextCW(char curr){
    if(curr == '^'){
        return '>';
    }else if(curr == '>'){
        return 'v';
    }else if(curr == 'v'){
        return '<';
    }else{
        return '^';
    }
}

char getNextAntiCW(char curr){
    if(curr == '^'){
        return '<';
    }else if(curr == '<'){
        return 'v';
    }else if(curr == 'v'){
        return '>';
    }else{
        return '^';
    }
}

char getNextCWnth(char curr, int n){
    int res = n%4;
    if(!res){ return curr; }
    while(res--){
        curr = getNextCW(curr);
    }
    return curr;
}

char getNextAntiCWnth(char curr, int n){
    int res = n%4;
    if(!res){ return curr; }
    while(res--){
        curr = getNextAntiCW(curr);
    }
    return curr;
}

int main(){
    fastInputOutput();
    char s, e;cin>>s>>e;
    int n;cin>>n;
    char p1 = getNextAntiCWnth(s, n), p2 = getNextCWnth(s, n);
    if(p1 == p2){
        cout<<"undefined\n";
    }else{
        cout<<((p1 == e)? "ccw":"cw")<<endl;
    }
    return 0;
}
