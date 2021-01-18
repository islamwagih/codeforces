#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string a, b;
    int pointsForA = 0, pointsForB = 0;
    for(int i=0;i<n;i++){
        string currTeam;cin>>currTeam;
        if(i == 0){
            pointsForA++;
            a = currTeam;
            continue;
        }
        if(currTeam == a){
            pointsForA++;
        }else{
            b = currTeam;
            pointsForB++;
        }
    }
    if(pointsForA > pointsForB){
        cout<<a<<endl;
    }else{
        cout<<b<<endl;
    }
    return 0;
}

