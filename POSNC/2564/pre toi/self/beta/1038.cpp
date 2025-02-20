#include <bits/stdc++.h>

using namespace std;
int n,k;
double dp[(1<<21)];
double a[21][21];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]/=100;
        }
    }
    dp[0] = 1;
    for(int i=0;i<(1<<n);i++){
        int cnt = __builtin_popcount(i);
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                dp[i] = max(dp[i],dp[i^(1<<j)]*a[cnt-1][j]);
        }
    }
    printf("%.12lf\n",dp[(1<<n)-1]*100);
    return 0;
}
