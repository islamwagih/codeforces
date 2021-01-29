#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}


int main(){
    fastInputOutput();
    int n, m;cin>>n>>m;
    int* cities = new int[n];
    int* towers = new int[m];

    for(int i=0;i<n;i++){
        cin>>cities[i];
    }

    for(int i=0;i<m;i++){
        cin>>towers[i];
    }

    int ans = -1;
    for(int i=0;i<n;i++){
        ///get the closest tower to the ith city
        int indexToClosestTower = lower_bound(towers, towers+m, cities[i]) - towers;
        ///lower bound returns index m which is out of range if all values less than the target we search
        ///so we have to decrease it by one to get a valid index
        if(indexToClosestTower == m){
            indexToClosestTower--;
        }
        ///lower bound returns first number not less than a target so if the target not exist it will return first number greater than our target
        ///so we have to take the minimum distance between this number and our target and the previous number and our target
        if(towers[indexToClosestTower] > cities[i] && indexToClosestTower > 0){
            int firstDistance = abs(towers[indexToClosestTower] - cities[i]);
            int secondDistance = abs(towers[indexToClosestTower-1] - cities[i]);
            indexToClosestTower = ( firstDistance > secondDistance ) ? indexToClosestTower-1:indexToClosestTower;
        }
        ///distance between the ith city and its closest tower
        int distance = abs(towers[indexToClosestTower] - cities[i]);
        ///the answer will be the maximum distance between ith city and the nearest tower to guarantee that we have covered all cities
        ans = max(distance, ans);
    }

    cout<<ans<<endl;
    return 0;
}
