#include <bits/stdc++.h>

using namespace std;
int a[1005][1005]={};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        a[x+1][y+1]++;
    }

    for(int i=1;i<=1001;i++){
        for(int j=1;j<=1001;j++){
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }

    while(m--){
        int x,y,r; cin>>x>>y>>r;
        x++,y++;
        int xr = min(x+r,1001);
        int yr = min(y+r,1001);
        int rx = max(x-r-1,0);
        int ry = max(y-r-1,0);
        cout<<a[min(x+r,1001)][min(y+r,1001)]-a[min(x+r,1001)][max(y-r-1,0)]-a[max(x-r-1,0)][min(y+r,1001)]+a[max(x-r-1,0)][max(y-r-1,0)]<<'\n';
    }
    return 0;
}
