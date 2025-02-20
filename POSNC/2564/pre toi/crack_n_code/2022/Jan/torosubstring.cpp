#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100005];
int b[100005];
int dp[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>s;
    s = ' '+s;
    for(int i=n;i>0;i--){
        a[i] = a[i+1];
        b[i] = b[i+1];
        if(s[i]=='A')
            a[i]++;
        else
            b[i]++;
    }
    dp[0] = 0;
    for(int i=n;i>0;i--){
        dp[i] = dp[i+1];
        if(a[i]>b[i])
            dp[i]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<b[i];
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(a[1]-a[i+1]>b[1]-b[i+1]){
            cout<<i<<" ";
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
