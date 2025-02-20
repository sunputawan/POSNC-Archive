#include <bits/stdc++.h>

using namespace std;
char a[1001];
int n;
int dp[1001][1001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=2;k<=n;k++){
        for(int i=1;i<=n-k+1;i++){
            int j = i+k-1;
            if(a[i]==a[j])
                dp[i][j] = 1+dp[i+1][j-1];
            else
                for(int l=i;l<j;l++){
                    dp[i][j] = max(dp[i][j],dp[i][l]+dp[l+1][j]);
                }
        }
    }
    cout<<dp[1][n]<<endl;
}
