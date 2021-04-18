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

map<ll, set<int>> record;
vector<pair<ll, bool>> arr(150100);

int main(){
    fastInputOutput();
    int sz;cin>>sz;
    for(int i=0;i<sz;i++){
        cin>>arr[i].first;
        arr[i].second = 1;
        record[arr[i].first].insert(i);
    }

    for(auto& PAIR:record){
        int setSize = PAIR.second.size();
        if(setSize > 1){
            int i = 0, stop = (setSize%2 == 0) ? 0:1;
            for(auto idx:PAIR.second){
                if(i%2 == 0){
                    arr[idx].second = false;
                    setSize--;
                }else{
                    arr[idx].first *= 2;
                    record[arr[idx].first].insert(idx);
                    setSize--;
                }
                if(setSize == stop){
                    break;
                }
                i++;
            }
        }
    }

    int cnt = 0;
    for(auto elem:arr){
        if(elem.second == 1){
            cnt++;
        }
    }

    cout<<cnt<<endl;
    for(auto elem:arr){
        if(elem.second){
            cout<<elem.first<<' ';
        }
    }

    return 0;
}

