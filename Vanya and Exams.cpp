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

vector<pair<int, int>> exams;
#define essay first
#define grade second

int main(){

    fastInputOutput();
    int n, r, avg;
    cin>>n>>r>>avg;

    ll sum = 0, minEssays = 0;
    for(int i=0;i<n;i++){
        pair<int, int> exam;
        cin>>exam.grade>>exam.essay;
        exams.push_back(exam);
        sum+=exam.grade;
    }

    if(sum/n < avg){
        sort(exams.rbegin(), exams.rend());
        ll minGrades = (ll)avg*n - sum;
        while(minGrades){
            pair<int, int> currExam = exams.back();
            exams.pop_back();
            int remaining = r-currExam.grade;
            if(remaining >= minGrades){
                minEssays += minGrades*currExam.essay;
                minGrades = 0;
            }else{
                minEssays += (ll)remaining*currExam.essay;
                minGrades -= remaining;
            }
        }
    }

    cout<<minEssays<<endl;

    return 0;

}
