#include <bits/stdc++.h>
using namespace std;
int main(){
    int events;cin>>events;
    int freeOfficers = 0, failedCrimes = 0;
    while(events--){
        int event;cin>>event;
        if(event != -1){
            ///free officers
            freeOfficers+=event;
        }else{
            if(freeOfficers == 0){
                failedCrimes++;
            }else{
                freeOfficers--;
            }
        }
    }
    cout<<failedCrimes<<endl;
    return 0;
}
