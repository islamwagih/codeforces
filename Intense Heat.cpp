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
    int n, k;cin>>n>>k;
    int* temps = new int[n];
    double allSum = 0;
    for(int i=0;i<n;i++){
        cin>>temps[i];
        allSum += temps[i];
    }
    double bigTemp = -1, winSize = 0;
    while(k < n){
        ///calculate the biggest temp with k window size
        ///assume the first k is the biggest
        double sum = 0;
        for(int i=0;i<k;i++){
            sum+=temps[i];
        }

        bigTemp = max(sum/k, bigTemp);
        int left = 0, right = k;

        while(right < n){
            sum += temps[right];
            sum -= temps[left];
            bigTemp = max(bigTemp, sum/k);
            right++,left++;
        }
        k++;
    }

    bigTemp = max(bigTemp, allSum/n);

    cout<<fixed<<setprecision(15)<<bigTemp<<endl;

    return 0;
}
 
