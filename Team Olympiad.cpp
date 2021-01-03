#include <bits/stdc++.h>
using namespace std;
int minArr(int arr[], int s){
    int minimum = arr[0];
    for(int i=1;i<s;i++){
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}
int main(){
    int n, num;cin>>n;
    int freArr[3] = {0};
    vector<int> programming, math, pe;
    for(int i=0;i<n;i++){
        cin>>num;
        freArr[num-1]++;
        if(num == 1){
            programming.push_back(i+1);
        }else if(num == 2){
            math.push_back(i+1);
        }else{
            pe.push_back(i+1);
        }
    }
    int teams = minArr(freArr, 3);
    cout<<teams<<endl;
    int idx = 0;
    while(teams--){
        cout<<programming[idx]<<' '<<math[idx]<<' '<<pe[idx]<<endl;
        idx++;
    }
    return 0;
}
