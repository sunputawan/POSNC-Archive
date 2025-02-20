#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int dp[500005];
int rock[500005];
vector<int> from[500005];
int main(){
    cin>>n>>m>>k;
    dp[1] = 1;
    while(m--){
        int a,b;
        cin>>a>>b;
        from[b].push_back(a);
    }
    while(k--){
        int x; cin>>x;
        rock[x] = 1;
    }
    for(int i=2;i<=n;i++){
        if(!rock[i-1])
            dp[i] = dp[i-1];
        for(int j:from[i])
            dp[i] |= dp[j];
    }
    cout<<dp[n]<<' ';
    if(!dp[n]){
        for(int i=n-1;i>0;i--){
            if(dp[i]){
                cout<<i<<endl;
                return 0;
            }
        }
    }
}
