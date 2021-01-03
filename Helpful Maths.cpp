#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> numbers;
    string operation;cin>>operation;
    int operationSize = operation.size();
    for(int i=0;i<operationSize;i++){
        if(operation[i] != '+'){
            numbers.push_back(operation[i] - '0');
        }
    }
    sort(numbers.begin(), numbers.end());
    int vecSize = numbers.size();
    for(int i=0;i<vecSize-1;i++){
        cout<<numbers[i]<<'+';
    }
    cout<<numbers[vecSize-1]<<endl;
    return 0;
}

