#include <bits/stdc++.h>

using namespace std;
double dp[100005];
int main(){
    dp[1] = 1;
    for(int i=2;i<=100000;i++){
        dp[i] = dp[i-1]+log10(i);
    }
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        cout<<(long long)dp[x]<<'\n';
    }
    return 0;
}