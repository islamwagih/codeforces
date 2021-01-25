#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


int main(){
    fastInputOutput();
    int n, k1, k2;
    cin>>n>>k1>>k2;
    int* A = new int[n];
    int* B = new int[n];
    multiset<int> absDiff;
    for(int i = 0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
        absDiff.insert(abs(A[i] - B[i]));
    }
    ///loop for total number of iteration
    for(int i=0;i<(k1+k2);i++){
        auto it = absDiff.end();
        it--;///to go to maximum abs diff(end of the multiset)
        int value = *it;
        absDiff.erase(it);
        absDiff.insert(abs(value-1));
    }

    long long minError = 0;
    for(auto val:absDiff){
        minError += (long long)val*val;
    }
    cout<<minError<<endl;
    return 0;
}

