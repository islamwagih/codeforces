#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int hh;string mm;cin>>hh>>mm;
    int h,c,d,n;cin>>h>>d>>c>>n;
    double newPrice = c - 0.2*c;
    int toBuy = 1;
    if(hh >= 20){
        ///go right away to the shop it's discount :"D
        while(toBuy*n < h){
            toBuy++;
        }
        cout<<fixed<<setprecision(4)<<toBuy*newPrice<<endl;
    }else{
        ///see if we can wait until the discount activated
        ///calculate the penalty
        int totalMin = 0;
        if(mm != "00"){
            int imm = 0;
            if(mm[0] == '0'){
                ///0-9
                imm = mm[1]-48;
            }else{
                imm = stoi(mm);
            }
            totalMin = (19-hh)*60 + 60-imm;
        }else{
            totalMin = (20-hh)*60;
        }
        int newH = h + d*totalMin;
        int newToBuy = 1;
        while(newToBuy*n < newH){
            newToBuy++;
        }
        while(toBuy*n < h){
            toBuy++;
        }
        cout<<fixed<<setprecision(4)<<min((double)newToBuy*newPrice, (double)toBuy*c)<<endl;
    }
    return 0;
}
