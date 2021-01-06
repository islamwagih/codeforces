#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* newArr = new int[n];
    for(int i=0;i<n;i++){
        newArr[arr[i]-1] = i+1;
    }
    for(int i=0;i<n;i++){
        cout<<newArr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
