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

multiset<int> arr;
int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        arr.insert(val);
    }
    if(k > 0 && k < n){
        auto it = arr.begin();
        advance(it, k-1);
        int first = *it;
        advance(it, 1);
        int second = *it;
        if(second > first){
            cout<<first<<endl;
        }else{
            cout<<-1<<endl;
        }
    }else if(k == 0){
        int smallest = *(arr.begin());
        if(smallest == 1){
            cout<<-1<<endl;
        }else{
            cout<<1<<endl;
        }
    }else{
        int biggest = *(arr.rbegin());
        cout<<biggest<<endl;
    }
    return 0;
}
 
