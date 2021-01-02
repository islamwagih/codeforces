#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int time1 = 0, time2 = d;
    int g = ceil((double)n/k);
    for(int i=0;i<g;i++){
        if(time1 <= time2){
            time1 += t;
        }else{
            time2 += t;
        }
    }
    if(max(time1, time2) < g*t){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
