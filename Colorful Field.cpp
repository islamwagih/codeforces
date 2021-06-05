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
    void log(char* msg, ll val = 0){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void log(string& msg, ll val = 0){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void log(string&& msg, ll val = 0){
        if(loggerIsWorking){
            cout<<msg<<" "<<val<<endl;
        }
    }
    void turnOf(){
        loggerIsWorking = 0;
    }
    void turnOn(){
        loggerIsWorking = 1;
    }
};

int transformOneDimentional(int i, int j, int c){
    i--, j--;
    return i*c+j;
}

int MOD(int a, int n){
    return ((a%n)+n)%n;
}

set<pair<int, int>> setOfWasted;

int main(){
    fastInputOutput();
    Logger screen;
    int n,m,k,q;
    ///negative mod -> ((a%n)+ n)%n

    cin>>n>>m>>k>>q;
    pair<int, int>* wastedCells = new pair<int, int>[k];
    for(int i=0;i<k;i++){
        pair<int, int> cell;
        cin>>cell.first>>cell.second;
        wastedCells[i] = cell;
        setOfWasted.insert(cell);
    }
    sort(wastedCells, wastedCells+k);
    ///carrots -> 1, kiwi -> 2, grapes -> 3
    int arr[3] = {1, 2, 3};
    for(int i=0;i<q;i++){
        ///lower bound range [first, last)
        pair<int, int> currCell;cin>>currCell.first>>currCell.second;
        if(setOfWasted.find(currCell) != setOfWasted.end())
        {
            ///found a wasted cell
            cout<<"Waste\n";
            continue;
        }

        int prvWastedCells = lower_bound(wastedCells, wastedCells+k, currCell) - wastedCells;
        int ind = transformOneDimentional(currCell.first, currCell.second, m)-prvWastedCells;
        int value = arr[MOD(ind, 3)];

        switch(value)
        {
            case 1:
                cout<<"Carrots\n";
                break;
            case 2:
                cout<<"Kiwis\n";
                break;
            default:
                cout<<"Grapes\n";
                break;
        }
    }
    return 0;
}


