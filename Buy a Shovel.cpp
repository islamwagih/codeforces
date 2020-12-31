#include <iostream>
using namespace std;
int main(){
    int k,r;cin>>k>>r;
    if(k%10==0 || (k-r)%10==0){
        cout<<1<<endl;
        return 0;
    }
    int numToBuy = 2;
    while(numToBuy < 10){
        if((numToBuy*k)%10 == 0 || ((numToBuy*k)-r)%10 == 0){
            cout<<numToBuy<<endl;
            return 0;
        }
        numToBuy++;
    }
    cout<<numToBuy<<endl;
    return 0;
}
