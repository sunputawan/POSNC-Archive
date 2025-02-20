#include <bits/stdc++.h>

using namespace std;
int a[1005][1005];
int mark[100001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        a[x][y] = 1;
    }

    while(m--){
        int x,y,r;
        cin>>x>>y>>r;
        int ans = 0;
        for(int i=max(x-r,0);i<=min(x+r,1000);i++){
            for(int j=max(y-r,0);j<=min(y+r,1000);j++){
                if(a[i][j]){
                    a[i][j] = 0;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
