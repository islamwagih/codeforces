#include <bits/stdc++.h>
using namespace std;

char generateRandomLowerCaseLetter(int val){
    char random = ((val + rand())%26) + 97;
    return random;
}

bool inVec(vector<char> vec, char t){
    int maxSize = vec.size();
    for(int i=0;i<maxSize;i++){
        if(vec[i] == t){
            return true;
        }
    }
    return false;
}

int generateRandomIdx(int val, int s){
    int idx = (val+rand()) % s;
    return idx;
}

int main(){
    int n;///password length
    int k;///distinct letters
    int seed = 0;///to start generating random letters
    cin>>n>>k;
    vector<char> included;///contains letters that have been used
    string newPass = "";///the new  password
    int currDis = 0;///current distinct chars in the new pass
    for(int i=0;currDis<k;i++){
        ///must be distinct
        char temp = generateRandomLowerCaseLetter(seed++);
        if(!inVec(included, temp)){
            newPass+=temp;
            included.push_back(temp);
            currDis++;
        }
    }
    ///must be included before
    int remaining = n-k; /// the remaining letters to complete a password with length b
    int currRep = 0; ///to count number of chars that joined to the the new password
    int innerSeed = 0;///to generate random idx of one of letters in newPass
    for(int i=0;currRep<remaining;i++){
        int idx = generateRandomIdx(innerSeed++, newPass.size());
        char temp = newPass[idx];
        ///to ensure that each two consecutive letters are distinct
        if(temp != newPass[newPass.size()-1]){
            currRep++;
            newPass+=temp;
        }
    }
    cout<<newPass<<endl;
    return 0;
}
