#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[4];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    string str;cin>>str;
    int totalCal = 0;
    for(int i=0;i<str.size();i++){
        totalCal += arr[str[i]-49];
    }
    cout<<totalCal<<endl;
    return 0;
}
