#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

vector<string> allMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int main(){
    fastInputOutput();
    string month;cin>>month;
    int target;cin>>target;
    int curr;
    for(int i=0;i<12;i++){
        if(allMonths[i] == month){
            curr = i;
            break;
        }
    }
    cout<<allMonths[(curr+target)%12]<<endl;

    return 0;
}
