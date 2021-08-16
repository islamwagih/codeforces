#include <bits/stdc++.h>
#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

map<int, int> record;
priority_queue<int, vector<int>, greater<int>> pq;
set<int> visited;
set<int> remaining;

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("closing.out", "w", stdout);
#endif

    int n,m,d;cin>>n>>m>>d;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        record[val] = i;
        pq.push(val);
        remaining.insert(val);
    }

    int* vec = new int[n];
    int days = 0;

    while(!pq.empty()){
        while(!pq.empty() && visited.find(pq.top()) != visited.end()){
            ///I already used it before
            pq.pop();
        }

        if(pq.empty()) break;

        days++;

        int mnVal = pq.top();
        visited.insert(mnVal);
        remaining.erase(mnVal);

        int next = mnVal+1+d;

        vec[record[mnVal]] = days;


        auto it = remaining.lower_bound(next);
        while(it != remaining.end()){
            ///i can take at same day
            int key = *it;
            visited.insert(key);
            remaining.erase(key);
            vec[record[key]] = days;
            next = key + 1 + d;
            it = remaining.lower_bound(next);
        }

    }

    cout<<days<<endl;
    for(int i=0;i<n;i++){
        cout<<vec[i]<<' ';
    }

    delete [] vec;

}
