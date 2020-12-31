#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low = 0, high = n-1, sereja = 0, dima = 0;
    int turns = 0;///determine what turn is it
    while(low<=high){
        if(turns%2 == 0){
            ///sereja turn
            if(arr[low] > arr[high]){
                sereja += arr[low++];
            }else{
                sereja += arr[high--];
            }
        }else{
            ///dima turn
            if(arr[low] > arr[high]){
                dima += arr[low++];
            }else{
                dima += arr[high--];
            }
        }
        turns++;
    }
    cout<<sereja<<' '<<dima<<endl;
    return 0;
}
