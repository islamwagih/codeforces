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

const int N = 1e5+5;
const int inf = 2e9+1;
multiset<int> keys;
int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int l = 0, r = 0, dis = 0;
    keys.insert(vec[0]);
    int mn, mx;
    while(l < n){
        mn = *keys.begin(), mx = *keys.rbegin();
        while(r < n-1 && mx - mn <= 1){
            r++;
            keys.insert(vec[r]);
            mn = *keys.begin();
            mx = *keys.rbegin();
        }
        //cout<<"r = "<<r<<", l = "<<l<<endl;
        if(mx-mn <= 1){
            //cout<<"if case : \n";
            //cout<<"dis before = "<<dis<<endl;
            dis = max(dis, r-l+1);
            //cout<<"dis after = "<<dis<<endl;
        }else{
           // cout<<"else case : \n";
            //cout<<"dis before = "<<dis<<endl;
            dis = max(dis, r-l);
           // cout<<"dis after = "<<dis<<endl;
        }

        keys.erase(keys.find(vec[l++]));
    }
    cout<<dis<<endl;
    return 0;
}
