#include <bits/stdc++.h>

using namespace std;
long long a[1000005];
long long qsum[1000005];
long long dp[1000005];
long long t,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qsum[i]=a[i]+qsum[i-1];
    }
    int q; cin>>q;
    while(q--){
        cin>>t;
        dp[1]=a[1];
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+a[i];
            if(i>k)
                dp[i] = min(dp[i],t+dp[i-k]+((qsum[i]-qsum[i-k])>>1));
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
