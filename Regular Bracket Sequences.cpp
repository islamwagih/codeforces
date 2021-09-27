#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 5;

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string seq = "";
        for(int i=0;i<n;i++) seq+="()";
        cout<<seq<<endl;
        n-=1;
        int sz = seq.size();
        while(n--){
            for(int i=0;i<sz-1;i++)
                if(seq[i] == ')' && seq[i+1] == '(')
                    swap(seq[i], seq[i+1]);
            cout<<seq<<endl;
        }
    }
    return 0;
}
