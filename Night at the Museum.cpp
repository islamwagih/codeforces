#include <iostream>
using namespace std;
int main(){
    char text[101];cin>>text;
    char curr = 'a';
    int fromRight, fromLeft, moves = 0;
    for(int i=0;text[i]!='\0';i++){
        if(i != 0){
            curr = text[i-1];
        }
        fromRight = abs(text[i] - curr);
        fromLeft = 26 - fromRight;
        moves += min(fromLeft, fromRight);
    }
    cout<<moves<<endl;
    return 0;
}
