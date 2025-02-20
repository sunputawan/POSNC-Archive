#include <bits/stdc++.h>

using namespace std;
string x,y,k;
int q,dp[1005][1005];
int main(){
    cin>>x>>y>>q;
    while(q--){
        memset(dp,0,sizeof(dp));
        cin>>k;
        dp[0][0] = 1;
        for(int i=0;i<=x.size();i++){
            for(int j=0;j<=y.size();j++){
                if(!dp[i][j]) continue;
                if(x[i]==k[i+j]) dp[i+1][j] = 1;
                if(y[j]==k[i+j]) dp[i][j+1] = 1;
            }
        }
        if(dp[x.size()][y.size()])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
