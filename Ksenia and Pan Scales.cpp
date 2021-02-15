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

int main(){
    fastInputOutput();
    string scale, untouched;cin>>scale>>untouched;
    int left = scale.find('|'), right = scale.size()-left-1, untouchedCount = untouched.size();
    int scaleSize = scale.size();
    if(left == right){
        if(untouchedCount%2 != 0){
            cout<<"Impossible\n";
            return 0;
        }else{
            for(int i=0;i<untouchedCount/2;i++){
                cout<<untouched[i];
            }
            for(int i=0;i<=left;i++){
                cout<<scale[i];
            }
            for(int i=untouchedCount/2;i<untouchedCount;i++){
                cout<<untouched[i];
            }
            for(int i=left+1;i<scaleSize;i++){
                cout<<scale[i];
            }
            cout<<endl;
        }
    }else if(left > right){
        if((right+untouchedCount) < left){
            cout<<"Impossible\n";
            return 0;
        }else if((right+untouchedCount) == left){
            for(int i=0;i<=left;i++){
                cout<<scale[i];
            }
            for(int i=left+1;i<scaleSize;i++){
                cout<<scale[i];
            }
            for(int i=0;i<untouchedCount;i++){
                cout<<untouched[i];
            }
            cout<<endl;
        }else{
            int remaining = right+untouchedCount - left;
            if(remaining%2 != 0){
                cout<<"Impossible\n";
                return 0;
            }else{
                for(int i=0;i<left;i++){
                    cout<<scale[i];
                }
                int forLeft = remaining/2;
                for(int i=0;i<forLeft;i++){
                    cout<<untouched[i];
                }
                for(int i=left;i<scaleSize;i++){
                    cout<<scale[i];
                }
                for(int i=forLeft;i<untouchedCount;i++){
                    cout<<untouched[i];
                }
                cout<<endl;
            }
        }
    }else{
        ///right > left
        if((left+untouchedCount) < right){
            cout<<"Impossible\n";
            return 0;
        }else if((left+untouchedCount) == right){
            for(int i=0;i<left;i++){
                cout<<scale[i];
            }
            for(int i=0;i<untouchedCount;i++){
                cout<<untouched[i];
            }
            for(int i=left;i<scaleSize;i++){
                cout<<scale[i];
            }
            cout<<endl;
        }else{
            int remaining = left+untouchedCount - right;
            if(remaining%2 != 0){
                cout<<"Impossible\n";
                return 0;
            }else{
                for(int i=0;i<left;i++){
                    cout<<scale[i];
                }
                int small = remaining/2, i, orgLeft = left;
                for(i=0;left < right+small;i++){
                    cout<<untouched[i];
                    left++;
                }
                for(int j=orgLeft;j<scaleSize;j++){
                    cout<<scale[j];
                }
                while(i < untouchedCount){
                    cout<<untouched[i++];
                }
                cout<<endl;
            }
        }
    }

    return 0;
}

