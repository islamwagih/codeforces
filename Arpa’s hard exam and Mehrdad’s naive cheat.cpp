#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    if(n == 0){
        cout<<1<<endl;
        return 0;
    }
    ///any number raised to any power the last digit will be just a sequence
    ///search for pisano series for additional information 
    int pisano[] = {8, 4, 2, 6};
    cout<<pisano[(n-1)%4]<<endl;
    return 0;
}

