#include <iostream>
using namespace std;
int main(){
    int y,w;cin>>y>>w;
    int maxOfTwo = max(y, w);
    int remainingChances = 6-maxOfTwo + 1;
    if(remainingChances == 1){
        cout<<1<<"/"<<6<<endl;
    }else if(remainingChances == 2){
        cout<<1<<"/"<<3<<endl;
    }else if(remainingChances == 3){
        cout<<1<<"/"<<2<<endl;
    }else if(remainingChances == 4){
        cout<<2<<"/"<<3<<endl;
    }else if(remainingChances == 5){
        cout<<5<<"/"<<6<<endl;
    }else{
        cout<<1<<"/"<<1<<endl;
    }
    return 0;
}
