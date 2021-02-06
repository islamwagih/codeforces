#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

unordered_map<int, int> allNumbers, oneDeleted, twoDeleted;
int main(){

    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        allNumbers[val]++;
    }

    for(int i=0;i<n-1;i++){
        int val;cin>>val;
        oneDeleted[val]++;
    }

    for(int i=0;i<n-2;i++){
        int val;cin>>val;
        twoDeleted[val]++;
    }

    for(auto it:allNumbers){
        if(oneDeleted.find(it.first) == oneDeleted.end()){
            cout<<it.first<<endl;
            break;
        }else{
            int num1 = oneDeleted[it.first], num2 = it.second;
            if(num1 != num2){
                cout<<it.first<<endl;
                break;
            }
        }
    }

    for(auto it:oneDeleted){
        if(twoDeleted.find(it.first) == twoDeleted.end()){
            cout<<it.first<<endl;
            break;
        }else{
            int num1 = it.second, num2 = twoDeleted[it.first];
            if(num1 != num2){
                cout<<it.first<<endl;
                break;
            }
        }
    }

    return 0;
}
