#include <iostream>

using namespace std;
string x = "ALGORITHMS";
string y = "ANALYSIS";
const int m = 10;
const int n = 8;
int dp[m+1][n+1];
int main(){
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int j=0;j<=n;j++)
        dp[0][j] = j;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 1+min(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[m][n];
}
