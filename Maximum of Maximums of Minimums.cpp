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

const int N = 1e3+5;
const int inf = 1e5+5;
const int M = 2*N;
const int mod = 1e9+7;

void printSet(multiset<int> s){
    for(auto i:s) cout<<i<<' ';
    cout<<endl;
}
int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    vector<int>vec(n);
    for(auto& i:vec)cin>>i;
    if(k == 1){
        cout<<*min_element(vec.begin(), vec.end());
    }else if(k == 2){
        multiset<int> A, B;
        for(int i=0;i<n-1;i++) A.insert(vec[i]);
        B.insert(vec[n-1]);
        int best = max(*A.begin(), *B.begin());
        for(int i=n-2;i>0;i--){
            A.erase(A.find(vec[i]));
            B.insert(vec[i]);
            best = max(best, max(*A.begin(), *B.begin()));
        }
        cout<<best<<endl;
    }else{
        cout<<*max_element(vec.begin(), vec.end());
    }
    return 0;
}
