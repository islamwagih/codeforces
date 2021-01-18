using namespace std;
int n,a,b,c,dp[4001];
int f(int x){
    if(x == 0){
        return 0;
    }
    if(x < 0 || (x < a && x < b && x < c)){
        return  INT_MIN;
    }
    if(dp[x]){
        return dp[x];
    }
    dp[x] = max(max(f(x-a), f(x-b)), f(x-c))+1;
    return dp[x];
}

int main(){
    cin>>n>>a>>b>>c;
    for(int i=0;i<4001;i++){
        dp[i] = 0;
    }
    cout<<f(n)<<endl;
    return 0;
}
