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

string rev(string toRev){
    int low = 0, high = getSize(toRev)-1;
    while(low < high){
        swap(toRev[low++], toRev[high--]);
    }
    return toRev;
}

int main(){
    fastInputOutput();
    string first, second;cin>>first;
    second = rev(first);
    cout<<first<<second<<endl;
    return 0;
}
 
