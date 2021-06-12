#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0;i<n-2;i++){
        double s = arr[i]+arr[i+1]+arr[i+2];
        s/=2;
        double a = arr[i], b = arr[i+1], c = arr[i+2];
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        if(area > 0){
            cout<<"YES\n";
            delete[] arr;
            return 0;
        }
    }
    cout<<"NO\n";
    delete[] arr;
    return 0;

}
