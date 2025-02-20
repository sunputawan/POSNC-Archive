#include <bits/stdc++.h>

using namespace std;
int a[1005],b[1005];
pair<int,int> dp[1005][1005];
int main(){
    int m,n; cin>>m>>n;
    dp[0][0] = {1,0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0] = dp[i-1][0];
        dp[i][0].second += a[i];
        if(dp[i][0].second>m){
            dp[i][0].first++;
            dp[i][0].second = a[i];
        }
    }
    for(int j=1;j<=n;j++){
        cin>>b[j];
        dp[0][j] = dp[0][j-1];
        dp[0][j].second += b[j];
        if(dp[0][j].second>m){
            dp[0][j].first++;
            dp[0][j].second = b[j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int day1 = dp[i-1][j].first;
            int sum1 = dp[i-1][j].second+a[i];
            if(sum1>m){
                day1++;
                sum1 = a[i];
            }
            int day2 = dp[i][j-1].first;
            int sum2 = dp[i][j-1].second+b[j];
            if(sum2>m){
                day2++;
                sum2 = b[j];
            }
            if(day1<day2){
                dp[i][j] = {day1,sum1};
            }
            else if(day1>day2){
                dp[i][j] = {day2,sum2};
            }
            else{
                if(sum1<sum2)
                    dp[i][j] = {day1,sum1};
                else
                    dp[i][j] = {day2,sum2};
            }
        }
    }
    cout<<dp[n][n].first<<'\n'<<dp[n][n].second<<'\n';
    return 0;
}
