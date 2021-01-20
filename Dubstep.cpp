#include <iostream>
using namespace std;
int main(){
    string remix;cin>>remix;
    string originalSong = "";
    int remixLength = remix.size(), i = 0, j = remixLength-1;
    while(i < remixLength-2){
        if(remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B'){
            i+=3;
        }else{
            break;
        }
    }

    while(j > 1){
        if(remix[i] == 'B' && remix[i-1] == 'U' && remix[i-2] == 'W'){
            j-=3;
        }else{
            break;
        }
    }

    while(i <= j){
        if(i+2 <= j){
            if(remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B'){
                i+=3;
                originalSong+=' ';
                continue;
            }
        }
        originalSong+=remix[i];
        i++;
    }

    cout<<originalSong<<endl;
    return 0;
}

