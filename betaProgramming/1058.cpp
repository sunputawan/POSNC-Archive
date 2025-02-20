#include <bits/stdc++.h>

using namespace std;
char arr[1005][1005];
int l[1005][1005],r[1005][1005],u[1005][1005],d[1005][1005];
void solve(void){
    int m,n; cin>>n>>m;
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(u,0,sizeof(u));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]=='1')
                l[i][j] = l[i][j-1]+1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--){
            if(arr[i][j]=='1')
                r[i][j] = r[i][j+1]+1;
        }
    }

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(arr[i][j]=='1')
                u[i][j] = u[i-1][j]+1;
        }
    }

    for(int j=1;j<=m;j++){
        for(int i=n;i>0;i--){
            if(arr[i][j]=='1')
                d[i][j] = d[i+1][j]+1;
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mx = max(mx,max(l[i][j],r[i][j]) + max(u[i][j],d[i][j])-1);
        }
    }
    cout<<mx<<'\n';
    return;
}
int main(){
    int k; cin>>k;
    while(k--){
        solve();
    }
}