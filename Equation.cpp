///Given C calc X to achieve this formula X^2 + X^0.5 = C
#include <bits/stdc++.h>
using namespace std;
double findX(double c){
    double low = 1, high = 1e9, mid;
    while(low <= high){
        mid = low+((high-low)/2.0);
        double ans = (mid*mid)+sqrt(mid);
        if(ans == c){
            return mid;
        }else if(ans > c){
            high = mid-1e-9;
        }else{
            low = mid+1e-9;
        }
    }
    return mid;
}

int main(){
    double value;cin>>value;
    cout<<fixed<<setprecision(15)<<findX(value)<<endl;
    return 0;
}

