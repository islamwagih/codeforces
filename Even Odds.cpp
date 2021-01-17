#include <iostream>
using namespace std;

long long ithEven(long long n){
    return n*2;
}

long long ithOdd(long long n){
    return (n*2)-1;
}

int main(){
    long long n,k;cin>>n>>k;
    long long numOfEven = n/2, numOfOdd = n-numOfEven;
    if(k <= numOfOdd){
        cout<<ithOdd(k)<<endl;
    }else{
        cout<<ithEven(k-numOfOdd)<<endl;
    }
    return 0;
}


