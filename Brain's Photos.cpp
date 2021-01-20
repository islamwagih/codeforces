#include <iostream>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    bool bw = 1;
    for(int i=0;i<n*m;i++){
        char color;cin>>color;
        if(color == 'C' || color == 'M' || color == 'Y'){
            bw = 0;
        }
    }
    string output = (bw == 0)?"#Color":"#Black&White";
    cout<<output<<endl;
    return 0;
}

