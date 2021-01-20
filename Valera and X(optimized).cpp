#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    set<char> diags, others;
    char inDiag;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char curr;cin>>curr;
            if(i == j || i == n-(j+1)){
                diags.insert(curr);
                inDiag = curr;
            }else{
                others.insert(curr);
            }
        }
    }
    if(diags.size() == 1 && others.size() == 1){
        string output = (others.find(inDiag) != others.end()) ? "NO":"YES";
        cout<<output<<endl;
    }else{
        cout<<"NO\n";
    }
    return 0;
}

