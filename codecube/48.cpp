#include <bits/stdc++.h>

using namespace std;
int mod = 1e6+7;
int n,m,dp[50005];
int main(){
    cin>>n>>m;
    dp[0] = 1;
    while(n--){
        int v; cin>>v;
        for(int i=m;i>=v;i--){
            if(dp[i-v]){
                dp[i] += dp[i-v];
                dp[i] = (dp[i]%mod);
            }
        }
    }
    cout<<dp[m]<<'\n';

    return 0;
}