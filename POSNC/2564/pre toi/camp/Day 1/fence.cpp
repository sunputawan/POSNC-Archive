#include <bits/stdc++.h>

using namespace std;
int m,n,t;
int vertical[600][600]={};
int horizontal[600][600]={};
int ref[600][600]={};
int dp[600][600]={};
vector<int> ans;
void input(void){
    cin>>m>>n>>t;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 1;
            vertical[i][j] = 0;
            horizontal[i][j] = 0;
        }
    }
    for(int i=0;i<t;i++){
        int r,t; cin>>r>>t;
        dp[r][t] = 0;
    }
    vertical[0][0] = dp[0][0];
    horizontal[0][0] = dp[0][0];
    for(int j=1;j<n;j++)
        vertical[0][j] = dp[0][j];
    for(int i=1;i<m;i++)
        horizontal[i][0] = dp[i][0];
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            if(dp[i][j]!=0)
                vertical[i][j] = vertical[i-1][j]+1;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(dp[i][j]!=0)
                horizontal[i][j] = horizontal[i][j-1]+1;
        }
    }
}
int solve(void){
    int maxsq = 0;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(dp[i][j]==0) continue;
            int l = min(horizontal[i][j],vertical[i][j]);
            for(int k=l;k>=0;k--){
                if(min(vertical[i][j-k+1],horizontal[i-k+1][j])>=k )
                    maxsq = max(maxsq,k);
            }
        }
    }
    return maxsq;
}
int main(){
    input();
    ans.push_back(solve());
    input();
    ans.push_back(solve());
    cout<<ans[0]<<'\n'<<ans[1];
    return 0;
}
