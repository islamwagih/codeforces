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

unordered_map<int, int> hToCards;
int PyramidOfLengthH(int h){
    if(hToCards.find(h) != hToCards.end()){
        return hToCards[h];
    }
    int cards = 2;
    for(int i=h;i>1;i--){
        cards += 2*i+i-1;
    }
    hToCards[h] = cards;
    return cards;
}

int main(){
    fastInputOutput();
    int t;cin>>t;
    while(t--){
        int cards;cin>>cards;
        int maxLength = 25820, toBuild = 0;
        while(cards > 1){
            int cardsRequired = PyramidOfLengthH(maxLength);
            if(cardsRequired <= cards){
                cards -= cardsRequired;
                toBuild++;
            }else{
                maxLength--;
            }
        }
        cout<<toBuild<<endl;
    }
    return 0;
}
