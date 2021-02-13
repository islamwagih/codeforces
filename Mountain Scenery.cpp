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
    int n, k;cin>>n>>k;
    vector<pair<int, int>> coorSys(2*n+1);

    for(int i=0;i<2*n+1;i++){
        coorSys[i].first = i+1;
        cin>>coorSys[i].second;
    }

    int i = 0;
    while(k > 0){
        if(coorSys[i].first%2 == 0){
            coorSys[i].second--;
            int curr = i, prev = i-1, next = i+1;
            if(i == 0){
                if(coorSys[curr].second > coorSys[next].second){
                    k--;
                }else{
                    coorSys[curr].second++;
                }
            }else if(i == 2*n){
                if(coorSys[curr].second > coorSys[prev].second){
                    k--;
                }else{
                    coorSys[curr].second++;
                }
            }else{
                ///current point must be greater then previous one and next one
                if(coorSys[curr].second > coorSys[prev].second && coorSys[curr].second > coorSys[next].second){
                    k--;
                }else{
                    coorSys[curr].second++;
                }
            }
        }
        i++;
    }

    for(auto item:coorSys){
        cout<<item.second<<' ';
    }
    cout<<endl;

    return 0;
}

