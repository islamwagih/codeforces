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

///..RRRRRR...
///...LLLLLLL..
///...RRRRRRLLL...
int main(){

    fastInputOutput();
    int n;cin>>n;
    char* arr = new char[n];
    int fst, lst;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i] != '.'){
            fst = i;
            break;
        }
    }

    for(int i=n-1;i>-1;i--){
        if(arr[i] != '.'){
            lst = i;
            break;
        }
    }

    if(arr[fst] == arr[lst]){
        ///case ...RRRRRRRR....
        ///or case .....LLLLLL...
        if(arr[fst] == 'R'){
            cout<<fst+1<<' '<<lst+2<<endl;
        }else{
            cout<<lst+1<<' '<<fst<<endl;
        }
        return 0;
    }

    ///case ...RRRRRLLLL...
    int lastR;
    for(int i=0;i<n;i++){
        if(arr[i] == 'L'){
            lastR = i;
            break;
        }
    }

    cout<<fst+1<<' '<<lastR<<endl;

    return 0;
}
 
