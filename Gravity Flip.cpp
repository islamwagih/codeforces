#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> cols;
    int noc;cin>>noc;
    while(noc--){
        int ithCol;cin>>ithCol;
        cols.push_back(ithCol);
    }
    sort(cols.begin(), cols.end());
    for(int i=0;i<cols.size();i++){
        cout<<cols[i]<<' ';
    }
    cout<<endl;
    return 0;
}
