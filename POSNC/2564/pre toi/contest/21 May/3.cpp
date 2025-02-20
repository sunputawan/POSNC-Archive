#include <bits/stdc++.h>

using namespace std;
int a[601];
int dp[601][601];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = 0;
            }
        }
        for(int k=2;k<=n;k++){
            for(int i=1;i<=n-k+1;i++){
                int j = i+k-1;
                for(int l=i;l<j;l++){
                    int lsum = a[l]-a[i-1];
                    int rsum = a[j]-a[l];
                    if(lsum<rsum){
                        lsum*=2;
                    }
                    else{
                        rsum*=2;
                    }
                    dp[i][j] = max(dp[i][j],dp[i][l]+dp[l+1][j]+lsum+rsum);
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
