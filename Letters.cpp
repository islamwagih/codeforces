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

int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    ll* dorms = new ll[n],*letterRooms = new ll[m];
    for(int i=0;i<n;i++){
        cin>>dorms[i];
    }
    for(int i=0;i<m;i++){
        cin>>letterRooms[i];
    }
    ll* dormsPrefixSum = new ll[n];
    dormsPrefixSum[0] = dorms[0];
    for(int i=1;i<n;i++){
        dormsPrefixSum[i] = dormsPrefixSum[i-1]+dorms[i];
    }
    for(int i=0;i<m;i++){
        ll currLetterRoom = letterRooms[i];
        int index = lower_bound(dormsPrefixSum, dormsPrefixSum+n, currLetterRoom)-dormsPrefixSum;
        int dorm = index+1; ll room;
        if(index == 0){
            room = currLetterRoom;
        }else{
            room = currLetterRoom-dormsPrefixSum[index-1];
        }
        cout<<dorm<<" "<<room<<endl;
    }
    return 0;
}
