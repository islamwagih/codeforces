#include <iostream>
using namespace std;
bool isHere(int target, int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[4];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    int freeArr[4] = {0}, idx = 0, toBuy = 0;
    for(int i=0;i<4;i++){
        if(isHere(arr[i], freeArr, 4)){
            toBuy++;
        }else{
            freeArr[idx++] = arr[i];
        }
    }
    cout<<toBuy<<endl;
    return 0;
}
