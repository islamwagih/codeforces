#include <bits/stdc++.h>
using namespace std;

void endlines(int n){
    if(n < 1){
        return;
    }
    while(n--){
        cout<<endl;
    }
}

int main(){

    int n;cin>>n;
    map<int, int> eleToIdx;

    for(int i=0;i<n;i++){
        int value;cin>>value;
        eleToIdx.insert({value, i});
    }

    map<int, int>::reverse_iterator rit = eleToIdx.rbegin();
    int bigestIdx = eleToIdx[n];

    while(rit != eleToIdx.rend()){
        int currIdx = rit->second;
        if(currIdx == bigestIdx){
            endlines(currIdx);
        }
        if(currIdx > bigestIdx){
            endlines(currIdx-bigestIdx);
            bigestIdx = currIdx;
        }
        cout<<rit->first<<' ';
        rit++;
    }

    return 0;
}

