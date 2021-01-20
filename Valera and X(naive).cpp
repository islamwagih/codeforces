#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string two = "";
    char matrix[n][n];
    bool wrong = 0;
    ///input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            if(two.size() == 0){
                two+=matrix[i][j];
            }else{
                if(two.size() == 1){
                    if(matrix[i][j] != two[0]){
                        two+=matrix[i][j];
                    }
                }else{
                    if(matrix[i][j] != two[0] && matrix[i][j] != two[1]){
                        wrong = 1;
                    }
                }
            }
        }
    }
    if(wrong){
        cout<<"NO\n";
        return 0;
    }
    ///check for diagonals
    set<pair<int, int>> indices;
    char first = two[0], second = two[1];
    char mainDiag = matrix[0][0];
    for(int i=0,j=0;i<n;i++,j++){
        if(matrix[i][j] != mainDiag){
            wrong = 1;
            break;
        }
        indices.insert({i, j});
    }
    for(int i=0, j=n-1;i<n;i++,j--){
        if(matrix[i][j] != mainDiag){
            wrong = 1;
            break;
        }
        indices.insert({i, j});
    }
    if(wrong){
        cout<<"NO\n";
        return 0;
    }
    ///check for others
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pair<int, int> test;
            test.first = i, test.second = j;
            if(indices.find(test) == indices.end()){
                ///i, j not in both diags
                char curr = matrix[i][j];
                if(curr == mainDiag){
                    wrong = 1;
                    break;
                }
            }
        }
    }
    if(wrong){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}

