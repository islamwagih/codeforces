#include <iostream>
using namespace std;
int main(){
    string stones, instructions;
    cin>>stones>>instructions;
    int position = 1, insSize = instructions.size();
    for(int i=0;i<insSize;i++){
        if(stones[position-1] == instructions[i]){
            position++;
        }
    }
    cout<<position<<endl;
    return 0;
}
