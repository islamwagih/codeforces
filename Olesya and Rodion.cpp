#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;cin>>n>>t;
    if(n == 1 && t == 10){
        cout<<-1<<endl;
    }else{
        char* number = new char[n+1];
        for(int i=0;i<n;i++){
            number[i] = '0';
        }
        if(t == 10){
            number[0] = '1';
        }else{
            number[0] = t+48;
        }
        number[n] = '\0';
        cout<<number<<endl;
    }
    return 0;
}

