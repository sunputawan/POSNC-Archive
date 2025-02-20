#include <iostream>

using namespace std;
int arr[] = {10,22,9,33,21,50,41,60,80,15};
const int n = 10;
int dp[n+1];
int main(){
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(arr[i-1]>arr[j-1])
                dp[i] = max(dp[i],1+dp[j]);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
}
