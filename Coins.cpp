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

int main(){
    fastInputOutput();
    int arr[3];
    for(int i=0;i<3;i++){
        arr[i] = 0;
    }
    for(int i=0;i<3;i++){
        string query;cin>>query;
        if(query[1] == '>'){
            ///Like A>B
            arr[query[0]-'A']++;
        }else{
            ///like A<B
            arr[query[2]-'A']++;
        }
    }
    if(arr[0] == arr[1] && arr[1] == arr[2]){
        cout<<"Impossible\n";
    }else{
        char first, sec, third;
        for(int i=0;i<3;i++){
            if(arr[i] == 0){
                first = i+'A';
            }else if(arr[i] == 1){
                sec = i+'A';
            }else{
                third = i+'A';
            }
        }
        cout<<first<<sec<<third<<endl;
    }
    return 0;
}

