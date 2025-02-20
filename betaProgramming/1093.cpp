#include <iostream>

using namespace std;
int dp[2005][2005];
int a[2005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp[1][i] = max(dp[1][i-1],dp[3][i-1]-a[i]);
        for(int j=1;j<=i;j++){
            dp[j][i] = max(dp[j][i-1],dp[j+2][i-1]+a[i]);
        }
    }
}