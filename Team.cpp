#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int ps = 0;
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        if(a+b+c >= 2){
            ps++;
        }
    }
    cout<<ps<<endl;
    return 0;
}
