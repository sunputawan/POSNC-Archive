#include <bits/stdc++.h>

using namespace std;
long long dp[1000005][3];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int a; cin>>a;
        if(i&1) a = -a;
        dp[i][0] = dp[i-1][0] + a;
        dp[i][1] = min(dp[i-1][0],dp[i-1][1]) - a;
        dp[i][2] = min(dp[i-1][1],dp[i-1][2]) + a;
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<'\n';
}