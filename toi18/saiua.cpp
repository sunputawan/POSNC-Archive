#include <bits/stdc++.h>

using namespace std;
long long a[5005],dp1[5005][5005],dp2[5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp1[i][i] = a[i];
    }
    for(int sz=2;sz<=n;sz++){
        for(int l=1;l<=n-sz+1;l++){
            int r = l+sz-1;
            dp1[l][r] = max(a[l] + dp1[l+1][r] , a[r] + dp1[l][r-1])+abs(a[l]-a[r]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            dp2[i] = max(dp2[i],dp2[j]+dp1[j+1][i]);
    }
    cout<<dp2[n]<<'\n';

    return 0;
}
/*
7
16 16 3 3 5 19 19
6
16 4 30 20 21 7
8
15 5 8 10 10 3 11 10
5
5 8 5 11 2
*/