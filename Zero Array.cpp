///Gym Question
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

map<int, int> record;

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] != 0){
                record[arr[i]]++;
            }
        }
        for(int i=0;i<q;i++){
            int qNum;cin>>qNum;
            if(qNum == 2){
                cout<<record.size()<<endl;
            }else{
                int p,v;cin>>p>>v;
                int oldVal = arr[p-1];
                int newVal = v;
                if(oldVal != 0){
                    int occ = record[oldVal];
                    if(occ == 1){
                        record.erase(oldVal);
                    }else{
                        record[oldVal]--;
                    }
                }
                arr[p-1] = v;
                if(newVal != 0){
                    record[newVal]++;
                }
            }
        }
        delete[] arr;
        record.clear();
    }
    return 0;
}

