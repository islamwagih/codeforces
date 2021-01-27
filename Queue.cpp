#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    int* improvedQueue = new int[n];

    for(int i=0;i<n;i++){
        int value;cin>>value;
        improvedQueue[i] = value;
    }

    sort(improvedQueue, improvedQueue+n);
    ll waitingTime = 0, satisfiedClients = 0;

    for(int i=0;i<n;i++){
        int curr = improvedQueue[i];
        if(waitingTime <= curr){
            satisfiedClients++;
            waitingTime += curr;
        }
    }


    cout<<satisfiedClients<<endl;
    return 0;
}
