#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int, int>> priceToQuality(n);
    for(int i=0;i<n;i++){
        cin>>priceToQuality[i].first>>priceToQuality[i].second;
    }
    sort(priceToQuality.begin(), priceToQuality.end());
    bool happy = 0;
    for(int i=0;i<n-1;i++){
        if(priceToQuality[i].second > priceToQuality[i+1].second){
            happy = 1;
            break;
        }
    }
    cout<<((happy) ? "Happy Alex" : "Poor Alex")<<endl;
    return 0;
}

