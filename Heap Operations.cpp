#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

priority_queue<int> heap;
vector<pair<string, int>> output;

int main(){

    fastInputOutput();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string command;cin>>command;
        if(command == "insert"){
            int val;cin>>val;
            heap.push(-val);
            output.push_back({"insert ", val});
        }else if(command == "removeMin"){
            if(heap.empty()){
                output.push_back({"insert ", 0});
            }else{
                heap.pop();
            }
            output.push_back({"removeMin ", -1});
        }else{
            int val;cin>>val;
            while(!heap.empty() && val > -heap.top()){
                output.push_back({"removeMin ", -1});
                heap.pop();
            }
            if(heap.empty() || val < -heap.top()){
                output.push_back({"insert ", val});
                heap.push(-val);
            }
            output.push_back({"getMin ", val});
        }

    }

    int maxSize = output.size();
    cout<<maxSize<<endl;
    for(int i=0;i<maxSize;i++){
        cout<<output[i].first;
        if(output[i].first == "removeMin "){
            cout<<endl;
        }else{
            cout<<output[i].second<<endl;
        }
    }

    return 0;
}
