#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = (2e5)+5;
int arr[N];
int n;
bool sorted(){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}
int main(){

    fastInputOutput();
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int low = -1;
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            low = i;
            break;
        }
    }
    if(low == -1){
        cout<<"yes\n1 1\n";
    }else{
        int hold = arr[low], high = low+1;
        while(high < n && arr[high] < hold) high++;
        reverse(arr+low, arr+high);
        if(sorted()){
            cout<<"yes\n";
            cout<<low+1<<' '<<high<<endl;
        }else{
            cout<<"no\n";
        }
    }
    return 0;

}
