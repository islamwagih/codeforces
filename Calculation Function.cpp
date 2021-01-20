#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    ll evens = n/2, odds = n-evens;
    if(evens == odds){
        cout<<evens<<endl;
    }else{
        cout<<evens-n<<endl;
    }
    return 0;
}
