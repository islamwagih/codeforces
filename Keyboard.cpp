#include <iostream>
using namespace std;
int main(){
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,.//\n";
    char fault;cin>>fault;
    string msg;cin>>msg;
    int msgSize = msg.size();
    for(int i=0;i<msgSize;i++){
        short fixed = (fault == 'R') ? -1 : 1;
        msg[i] = keyboard[keyboard.find(msg[i])+fixed];
    }
    cout<<msg<<endl;
    return 0;
}

