#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5+10;
const int inf = 1e9+5;
const int M = 2*N;
const int mod = 1e9+7;


int main(){
    fastInputOutput();
    int n;cin>>n;
    vector<int> arr(n);
    for(int& i:arr) cin>>i;
    int ans = inf;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int first = arr[0]+i, sec = arr[1]+j;
            int diff = sec - first, cnt = abs(i)+abs(j);
            int last = sec;
            for(int i=2;i<n;i++){
                int next = last+diff;
                if(abs(next-arr[i]) == 1) cnt++;
                if(abs(next-arr[i]) > 1){
                    cnt = inf;
                    break;
                }
                last = next;
            }
            ans = min(ans, cnt);
        }
    }
    cout<<(ans == inf ? -1:ans)<<endl;
    return 0;
}
