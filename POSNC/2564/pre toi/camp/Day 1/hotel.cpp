#include <bits/stdc++.h>
#define INTMAX 500000009

using namespace std;
int dp[1000005];
int hotel(int n){
    if(n<=0)
        return 0;
    if(dp[n]==-1){
        int mincost = INTMAX;
            mincost = min(mincost,hotel(n-15)+3000);
            mincost = min(mincost,hotel(n-5)+1500);
            mincost = min(mincost,hotel(n-2)+800);
            mincost = min(mincost,hotel(n-1)+500);

        dp[n] = mincost;
    }
    return dp[n];
}
int main(){
    memset(dp,-1,sizeof(dp));

    int n; cin>>n;
    cout<<hotel(n);
    return 0;
}
