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

class Logger{
    bool loggerIsWorking = 1;
public:
    void log(char* msg){
        if(loggerIsWorking){
            cout<<msg<<endl;
        }
    }
    void log(string& msg){
        if(loggerIsWorking){
            cout<<msg<<endl;
        }
    }
    void log(string&& msg){
        if(loggerIsWorking){
            cout<<msg<<endl;
        }
    }
    void turnOf(){
        loggerIsWorking = 0;
    }
    void turnOn(){
        loggerIsWorking = 1;
    }
};

int main(){
    fastInputOutput();Logger screen;
    int n;cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ///catch the start of the error
    int first = -1, last = -1, i = 0;
    while(i<n-1){
        if(arr[i] > arr[i+1]){
            first = i;
            while(i < n-1){
                if(arr[i] >= arr[i+1]){
                    i++;
                }else{
                    last = i;
                    break;
                }
            }
            if(last == -1){
                last = n-1;
            }
            break;
        }
        i++;
    }
    if(first == -1){
        cout<<"yes"<<endl;
        cout<<1<<' '<<1<<endl;
    }else{
        int low = first, high = last;
        while(low < high){
            swap(arr[low], arr[high]);
            low++, high--;
        }
        ///check if sorted now
        for(int i=0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                cout<<"no\n";
                return 0;
            }
        }
        cout<<"yes"<<endl;
        cout<<first+1<<' '<<last+1<<endl;
    }
    delete[] arr;
    return 0;
}

