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

int n,l,r,x;
bool valid(int td, int mnv, int mxv){
    if(td < l || td > r){
        return false;
    }
    if((mxv-mnv) < x){
        return false;
    }
    return true;
}

int main(){
    fastInputOutput();
    cin>>n>>l>>r>>x;
    int problemSets = 0, totalDifficulty, minVal, maxVal;
    int* problems = new int[n];
    for(int i=0;i<n;i++){
        cin>>problems[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        totalDifficulty = 0, minVal = INT_MAX, maxVal = INT_MIN;
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                totalDifficulty += problems[i];
                minVal = min(minVal, problems[i]);
                maxVal = max(maxVal, problems[i]);
            }
        }
        if(valid(totalDifficulty, minVal, maxVal)){
            problemSets++;
        }
    }
    cout<<problemSets<<endl;
    return 0;
}

