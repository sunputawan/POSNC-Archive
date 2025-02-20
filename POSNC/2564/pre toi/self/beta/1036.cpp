#include <bits/stdc++.h>

using namespace std;

int n,k,cost;
vector<long long> dp((1<<8),INT_MAX);
int main(){
    cin>>n>>k;
    dp[0]=0;
    for(int i=0;i<n;i++){
        cin>>cost;
        int bit = 0;
        for(int j=0;j<k;j++){
            int x; cin>>x;
            if(x)
                bit |= (1<<j);
        }
        for(int j=0;j<(1<<k);j++){
            dp[j|bit] = min(dp[j|bit],dp[j]+cost);
        }
    }
    cout<<dp[(1<<k)-1]<<endl;
    return 0;
}
