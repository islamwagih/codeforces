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
    int n;cin>>n;
    map<int, int> M;
    int* arr = new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        M[arr[i]]++;
    }

    int* powerOfTwo = new int[31];
    powerOfTwo[0] = 1;
    int num = 2;
    for(int i = 1;i<31;i++){
        powerOfTwo[i] = num;
        num *= 2;
    }


    ull total = 0;
    for(int i=0;i<n;i++){
        int curr = arr[i];
        for(int j=0;j<31;j++){
            int remaining = powerOfTwo[j] - curr; ///curr + remaining == k(which is power of 2)
            if(M.find(remaining) != M.end()){
                if(remaining == curr){
                    total += (M[remaining] - 1);
                }else{
                    total += M[remaining];
                }
            }
        }
    }

    cout<<total/2<<endl;
    return 0;
}
