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

int rounder(double val){
    int intPart = val;
    double fPart = val-intPart;
    if(fPart < 0.5){
        return intPart;
    }
    return intPart+1;
}

int main(){
    fastInputOutput();
    int n, k;cin>>n>>k;
    int* arr = new int[n];
    double sum = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int score = rounder(sum/n);
    if(score >= k){
        cout<<0<<endl;
    }else{
        int minGrades = 0;
        while(rounder(sum/n) < k){
            sum += k;
            n++;
            minGrades++;
        }
        cout<<minGrades<<endl;
    }
    return 0;
}
