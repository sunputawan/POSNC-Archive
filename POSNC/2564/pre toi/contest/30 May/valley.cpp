#include <bits/stdc++.h>

using namespace std;
int r,c,ans;
int dp[105][105];
int a[105][105];
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
void play(int i,int j){
    if(dp[i][j]>0) return;
    dp[i][j] = 1;
    for(int k=0;k<4;k++){
        if(a[i][j]<a[i+di[k]][j+dj[k]]){
            play(i+di[k],j+dj[k]);
            dp[i][j] = max(dp[i][j],1+dp[i+di[k]][j+dj[k]]);
        }
    }
}
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            play(i,j);
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
