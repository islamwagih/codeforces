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


int main(){

    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n, k;cin>>n>>k;
        pair<int, int>* arr = new pair<int, int>[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second = i;
        }

        sort(arr, arr+n);

        int minSeq = 1;
        for(int i=1;i<n;i++){
           if(arr[i-1].second+1 != arr[i].second){
                minSeq++;
           }
        }


        cout<<((minSeq <= k) ? "Yes":"No")<<endl;
        delete[] arr;
    }
    return 0;
}
