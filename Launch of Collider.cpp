#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    bool* comp = new bool[n];

    ///right -> 1 && left -> 0
    for(int i=0;i<n;i++){
        char direction;cin>>direction;
        if(direction == 'R'){
            comp[i] = 1;
        }else{
            comp[i] = 0;
        }
    }

    vector<int> left, right;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        if(comp[i]){
            ///right
            right.push_back(val);
        }else{
            ///left
            left.push_back(val);
        }
    }

    int ms = INT_MAX;
    for(auto rightPoint:right){
        int nearestLeftIdx = lower_bound(left.begin(), left.end(), rightPoint)-left.begin();
        if(nearestLeftIdx == (int)left.size()){continue;}
        int leftPoint = left[nearestLeftIdx];
        int diff = leftPoint - rightPoint;
        if(diff % 2 != 0){
            ///no collision will happen to make sure consider the following situation the case of 2 -> right && 5 -> left
            continue;
        }
        ///collision will happen at time (leftPoint-rightPoint)/2 to make sure consider the following situation
        ///2 -> right && 4 -> left or 2 -> right && 6 -> left
        ms = min(ms, diff/2);
    }

    cout<<((ms == INT_MAX)?-1:ms)<<endl;

    return 0;
}

