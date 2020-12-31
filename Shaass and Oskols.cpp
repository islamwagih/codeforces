#include <iostream>
using namespace std;
int main(){
    int wiresNumber;cin>>wiresNumber;
    int* wires = new int[wiresNumber];
    for(int i=0;i<wiresNumber;i++){
        cin>>wires[i];
    }
    int shots;cin>>shots;
    while(shots--){
        int wire, birdNum;cin>>wire>>birdNum;
        int right = wires[wire-1] - birdNum;
        int left = wires[wire-1]-right-1;///sub from 1 because the bird killed
        wires[wire-1] = 0;///on longer birds on that wire
        if(wire == 1){
            ///left birds will go away
            wires[wire]+=right;
        }else if(wire == wiresNumber){
            ///right birds will go away
            wires[wire-2]+=left;
        }else{
            wires[wire]+=right;
            wires[wire-2]+=left;
        }
    }
    for(int i=0;i<wiresNumber;i++)
        cout<<wires[i]<<endl;
    return 0;
}
