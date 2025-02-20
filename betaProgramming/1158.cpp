#include <bits/stdc++.h>

using namespace std;
int qsum[1005][1005];
int main(){
    int m,n,k; cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>qsum[i][j];
            qsum[i][j] += qsum[i][j-1] + qsum[i-1][j] - qsum[i-1][j-1];
        }
    }
    int mx = 0;
    for(int i=k;i<=m;i++){
        for(int j=k;j<=n;j++){
            mx = max(mx,qsum[i][j]-qsum[i][j-k]-qsum[i-k][j]+qsum[i-k][j-k]);
        }
    }

    cout<<mx<<'\n';

    return 0;
}