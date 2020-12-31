#include <bits/stdc++.h>
using namespace std;

void toLowerCase(char input[]){
    int i = 0;
    while(input[i]!='\0'){
        if(input[i] <= 90 && input[i] >= 65){
            input[i] = input[i]+32;
        }
        i++;
    }
}

int strCmpIgnoreCase(char str1[], char str2[]){
    toLowerCase(str1);
    toLowerCase(str2);
    int i = 0; ///idx
    while(str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'){
        i++;
    }
    if(str1[i] == '\0' || str2[i] == '\0'){
        return 0;
    }
    if(str1[i] < str2[i]){
        return -1;
    }
    if(str2[i] < str1[i]){
        return 1;
    }
    return 0;
}

int main(){
    char a[101], b[101];cin>>a>>b;
    cout<<strCmpIgnoreCase(a, b)<<endl;
    return 0;
}
