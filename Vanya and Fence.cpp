#include <iostream>

using namespace std;

int main(){
    int arraySize, height, minimumWidth = 0;
    cin>>arraySize>>height;
    for(int i=0;i<arraySize;i++){
        int element;cin>>element;
        if(element > height){
            ///add 2 person must bend
            minimumWidth += 2;
        }else{
            ///add 1 person will not face any problems
            minimumWidth += 1;
        }
    }
    cout<<minimumWidth<<endl;
    return 0;
}
