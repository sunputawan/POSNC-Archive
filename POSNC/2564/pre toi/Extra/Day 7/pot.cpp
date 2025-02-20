#include <bits/stdc++.h>

using namespace std;
int dp[100001];
int main(){
    int n,k; cin>>n>>k;
    dp[0] = 1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=dp[i-1];
        if(i>k) sum-=dp[i-k-1];
        sum%=2009;
        sum = (sum+2009)%2009;
        dp[i] = sum;
    }
    cout<<(dp[n]%2009)<<endl;
    return 0;
}

