#include <iostream>
using namespace std;
int main(){
    int m = 5, n = 5, cell, diff = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>cell;
            if(cell == 1){
                diff = abs(i-2)+abs(j-2);
            }
        }
    }
    cout<<diff<<endl;
    return 0;
}

