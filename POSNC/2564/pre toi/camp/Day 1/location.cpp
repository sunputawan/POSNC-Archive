#include <bits/stdc++.h>

using namespace std;
int dp[600][600];
int counttree(int i,int j,int l){
    return dp[i][j]-dp[i-l][j]-dp[i][j-l]+dp[i-l][j-l];
}
void solve(void){
    int m,n,k;
    cin>>m>>n>>k;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        dp[a+1][b+1] = 1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] += dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
    }

    for(int l=min(n,m);l>1;l--){
        for(int i=l;i<=m;i++){
            for(int j=l;j<=n;j++){
                if(counttree(i,j,l)==counttree(i-1,j-1,l-2)){
                    cout<<l<<'\n';
                    return;
                }
            }
        }
    }
    cout<<1<<endl;
    return;
}
int main(){
    solve();
    solve();
    return 0;
}
