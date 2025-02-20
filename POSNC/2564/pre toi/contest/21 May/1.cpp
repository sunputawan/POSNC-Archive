#include <bits/stdc++.h>
using namespace std;
char a[2][5005];
long long dp[2][5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin>>q;
    int mod = 1e9+7;
    dp[0][0] = 1;
    dp[1][0] = 1;
    while(q--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[0][i];
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[1][i];
            dp[1][i] = 0;
        }
        for(int i=1;i<=n;i++){
            if(a[0][i]!='#'){
                if(a[0][i-1]!='#')
                    dp[0][i] = dp[0][i-1];
                if(a[1][i]!='#')
                    dp[0][i] += dp[1][i-1]%mod;
            }
            if(a[1][i]!='#'){
                if(a[1][i-1]!='#')
                    dp[1][i] = dp[1][i-1];
                if(a[0][i]!='#')
                    dp[1][i] += dp[0][i-1]%mod;
            }
        }
        cout<<(dp[0][n]+dp[1][n])%mod<<endl;
    }
}
