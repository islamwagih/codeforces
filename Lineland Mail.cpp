#include <iostream>
using namespace std;

int distance(int x1, int x2){
    if(x2 > x1){
        return x2-x1;
    }
    return x1-x2;
}

int main(){
    int n;cin>>n;
    int* cities = new int[n];
    for(int i=0;i<n;i++){
        cin>>cities[i];
    }
    int maxDis, minDis, value1, value2;
    for(int i=0;i<n;i++){
        if(i != 0 && i != n-1){
            value1 = distance(cities[i], cities[0]);
            value2 = distance(cities[i], cities[n-1]);
            maxDis = max(value1, value2);
            value1 = distance(cities[i], cities[i+1]);
            value2 = distance(cities[i], cities[i-1]);
            minDis = min(value1, value2);
        }else{
            maxDis = distance(cities[0], cities[n-1]);
            minDis = (i == 0) ? distance(cities[i], cities[i+1]) : distance(cities[i], cities[i-1]);
        }
        cout<<minDis<<' '<<maxDis<<endl;
    }
    return 0;
}
