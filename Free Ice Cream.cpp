#include <iostream>
using namespace std;
int main(){
    int_fast64_t n,x,dk = 0,amount;cin>>n>>x;
    char sign;
    while(n--){
        cin>>sign>>amount;
        if(sign == '+'){
            x += amount;
        }else{
            if(x >= amount){
                x -= amount;
            }else{
                dk++;
            }
        }
    }
    cout<<x<<' '<<dk<<endl;
    return 0;
}
