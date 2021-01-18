#include <bits/stdc++.h>
using namespace std;
 
bool isUnrated(int a[], int b[], int s){
    int lastIdx = s-1;
    for(int i=0;i<s;i++){
        if(a[i] != b[lastIdx--]){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n;cin>>n;
    int* before = new int[n];
    int* after = new int[n];
    bool rated = 0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        before[i] = a;
        after[i] = b;
        if(abs(a-b) > 0){
            rated = 1;
        }
    }
    if(rated){
        cout<<"rated\n";
        return 0;
    }
    sort(after, after+n);
    if(isUnrated(before, after, n)){
        cout<<"unrated\n";
    }else{
        cout<<"maybe\n";
    }
 
 
    return 0;
}
