#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}



int main(){

    fastInputOutput();
    int n;cin>>n;
    unordered_map<string, int> database;
    for(int i=0;i<n;i++){
        string name;cin>>name;
        auto it = database.find(name);
        if(it == database.end()){
            ///user not found
            cout<<"OK\n";
            database[name] = 0;
        }else{
            int number = it->second + 1;
            cout<<name<<number<<endl;
            database[name]++;
        }
    }

    return 0;
}

