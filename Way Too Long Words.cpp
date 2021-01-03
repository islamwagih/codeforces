#include <iostream>
using namespace std;
string intToStr(int number){
    string strNum = "";
    while(number){
        strNum += (number%10) + 48;
        number /= 10;
    }
    int high = strNum.size()-1, low = 0;
    while(low < high){
        int temp = strNum[low];
        strNum[low] = strNum[high];
        strNum[high] = temp;
        low++, high--;
    }
    return strNum;
}
int main(){

    int t;cin>>t;
    while(t--){
        string word,abb = "";cin>>word;
        int wordSize = word.size();
        if(wordSize > 10){
            abb+=word[0];
            abb+=intToStr(wordSize-2);
            abb+=word[wordSize-1];
            cout<<abb<<endl;
        }else{
            cout<<word<<endl;
        }
    }

    return 0;
}
