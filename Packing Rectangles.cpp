#include <iostream>
using namespace std;
int main(){
    int w,h,n;cin>>w>>h>>n;
    unsigned long long low = 1, high = 1e19, side = 1e19;
    while(low <= high){
        unsigned long long mid = low+((high-low)/2);
        unsigned long long numOfRec = (mid/w)*(mid/h);
        if(numOfRec >= n){
            if(mid < side){
                side = mid;
            }
            high = mid-1;
        }else if(numOfRec < n){
            low = mid+1;
        }
    }
    cout<<side<<endl;
    return 0;
}

