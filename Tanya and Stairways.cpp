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
    int* arr = new int[n];
    vector<int> steps;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int currStep = 1;
    for(int i=1;i<n;i++){
        if(arr[i] == 1){
            steps.push_back(currStep);
            currStep = 1;
        }else{
            currStep++;
        }
    }
    steps.push_back(currStep);
    cout<<steps.size()<<endl;
    for(auto step:steps){
        cout<<step<<' ';
    }
    cout<<endl;
    return 0;
}
