#include <iostream>
using namespace std;
int main(){
    ///we can make it even faster to print no if n less than 26 since all alphabet will be not present
    int n;cin>>n;
    char* str = new char[n];
    int* freq = new int[26];
    for(int i=0;i<26;i++){
        freq[i] = 0;
    }

    for(int i=0;i<n;i++){
        cin>>str[i];
        int charNum = str[i];
        ///if the ascii code for a char is less than 97 thats means it's an uppercase letter
        if(charNum < 97){
            ///add 32 to convert it to a lowercase letter, since any alphabet denoting it's lowercase is x and it's uppercase X then x-X will be 32
            charNum += 32;
        }
        ///a-a will be 0 and b-a will be 1 c-a will be 2 and  since all alphabet is 26 we need an array of 26 different character the index represent the letter
        ///and the value represent the number of occurrence
        freq[charNum - 'a']++;
    }

    bool pangram = 1;
    for(int i=0;i<26;i++){
       if(freq[i] < 1){
            pangram = 0;
            break;
       }
    }

    string printer = (pangram) ? "YES":"NO";
    cout<<printer<<endl;
    return 0;
}

