#include <bits/stdc++.h>
using namespace std;

int main(){

    int sze;cin>>sze;
    string bin;cin>>bin;
    int* freq = new int[2];
    freq[0] = freq[1] = 0;

    for(int i=0;i<sze;i++){
        if(bin[i] == '0'){
            freq[0]++;
        }else{
            freq[1]++;
        }
    }

    int deleted = min(freq[0], freq[1]) * 2;
    cout<<sze-deleted<<endl;

    return 0;
}
 
