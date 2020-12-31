#include <iostream>
using namespace std;
int main(){
    int squeezed = 0, emptyWaste = 0;
    int n,b,d;cin>>n>>b>>d;
    int* oranges = new int[n];
    for(int i=0;i<n;i++){
        cin>>oranges[i];
        if(oranges[i] <= b){
            squeezed += oranges[i];
            if(squeezed > d){
                emptyWaste++;
                squeezed = 0;
            }
        }
    }
    cout<<emptyWaste<<endl;
    return 0;
}
