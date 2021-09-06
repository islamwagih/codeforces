#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = (5e5)+5;
vector<int> vec;
vector<int> sh, bh;
int main(){

    fastInputOutput();
    int n;cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(), vec.end());

    for(int i=0;i<n/2;i++){
        bh.push_back(vec.back());
        vec.pop_back();
    }

    for(int i=n/2;i<n;i++){
        sh.push_back(vec.back());
        vec.pop_back();
    }

    int ans = n;
    while(sh.size() && bh.size()){
        if(bh.back() >= 2*sh.back()){
            sh.pop_back();
            ans--;
        }
        bh.pop_back();
    }

    cout<<ans<<endl;

    return 0;

}
