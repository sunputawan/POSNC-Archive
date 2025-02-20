#include <bits/stdc++.h>

using namespace std;
int dp[(1<<8)];
int main(){
    int n,k; cin>>n>>k;
    memset(dp,127,sizeof dp);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int cost; cin>>cost;
        int bit = 0;
        for(int j=0;j<k;j++){
            int x; cin>>x;
            if(x)
                bit |= (1<<j);
        }
        for(int j=0;j<(1<<k);j++){
            dp[bit|j] = min(dp[bit|j],cost+dp[j]);
        }
    }
    cout<<dp[(1<<k)-1]<<endl;
    return 0;
}
