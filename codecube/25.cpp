#include <bits/stdc++.h>

using namespace std;
long long n,arr[605],qsum[605],dp[605][605];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        qsum[i] = arr[i] + qsum[i-1];
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
            for(int k=i;k<j;k++){
                long long lsum = qsum[k]-qsum[i-1];
                long long rsum = qsum[j]-qsum[k];
                if(lsum<rsum){
                    dp[i][j] = max(dp[i][j],dp[k+1][j]+2*lsum+rsum);
                }
                else{
                    dp[i][j] = max(dp[i][j],dp[i][k]+lsum+2*rsum);
                }
            }
        }
    }
    /*for(int l=2;l<=n;l++){
        cout<<"l : "<<l<<'\n';
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
                printf("dp[%d][%d] : %d ",i,j,dp[i][j]);
        }
        cout<<'\n';
    }*/
    cout<<dp[1][n]<<'\n';
} 