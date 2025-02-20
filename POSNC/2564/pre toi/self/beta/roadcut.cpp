#include <bits/stdc++.h>

using namespace std;
int a[105][105];
int b[105][105];
int ax[105];
int ay[105];
int dpx[105];
int dpy[105];
int main(){
    int n,m,total = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            total+=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ax[i]+=a[i][j];
            dpx[i]+=b[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            ay[j]+=a[i][j];
            dpy[j]+=b[i][j];
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mx = max(mx,total-ax[i]+dpx[i-1]+dpx[i+1]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            mx = max(mx,total-ay[j]+dpy[j-1]+dpy[j+1]);
        }
    }
    cout<<mx<<'\n';
    return 0;
}
