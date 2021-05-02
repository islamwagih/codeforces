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

ll ncr(int n, int r = 2)
{

    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }

    }
    else{
        p = 1;
    }

    return p;
}

int main(){
    fastInputOutput();
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll totalCoincide = n;
    int l = 0, length = 1;
    for(int i=1;i<n;i++){
        if(arr[i] == arr[l]){
            length++;
        }else{
            if(length > 1){
                totalCoincide += ncr(length);
            }
            length = 1;
            l = i;
        }
    }
    if(length > 1){
        totalCoincide += ncr(length);
    }
    cout<<totalCoincide<<endl;
    return 0;
}
 
