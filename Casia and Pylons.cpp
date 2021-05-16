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
    int n;cin>>n;
    int* pylonsHeights = new int[n];
    for(int i=0;i<n;i++){
        cin>>pylonsHeights[i];
    }
    int currPylonHeight = 0, currEnergy = 0, spent = 0;
    for(int i=0;i<n;i++){
        if(currEnergy+currPylonHeight < pylonsHeights[i]){
            int difference = (pylonsHeights[i]-currEnergy)-currPylonHeight;
            spent += difference;
            currPylonHeight += difference;
        }
        currEnergy += (currPylonHeight-pylonsHeights[i]);
        currPylonHeight = pylonsHeights[i];
    }
    cout<<spent<<endl;
    //delete[] pylonsHeights;
    return 0;
}
 
