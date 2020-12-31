#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int antonWon = 0, danikWon = 0;
    char winner;
    while(n--){
        cin>>winner;
        if(winner == 'A'){
            antonWon++;
        }else{
            danikWon++;
        }
    }
    if(antonWon > danikWon){
        cout<<"Anton"<<endl;
    }else if(danikWon > antonWon){
        cout<<"Danik"<<endl;
    }else{
        cout<<"Friendship"<<endl;
    }
    return 0;
}
