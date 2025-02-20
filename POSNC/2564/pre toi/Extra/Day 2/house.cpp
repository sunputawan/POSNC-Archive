#include <bits/stdc++.h>

using namespace std;
int r,c,k;
int a[305][305];
int dp1[305][305];
int dp2[305][305];
int main(){
    cin>>r>>c>>k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
            if((i+j)%2)
                a[i][j]*=-1;
            dp1[i][j] = dp1[i-1][j]+a[i][j];
            dp2[i][j] = dp2[i][j-1]+a[i][j];
        }
    }
    int mx = -2000000000;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int v = dp1[min(i+k,r)][j]-dp1[max(i-k-1,0)][j];
            int h = dp2[i][min(j+k,c)]-dp2[i][max(j-k-1,0)];
            int now = v+h-a[i][j];
            if((i+j)%2)
                now*=-1;
            mx = max(mx,now);
        }
    }
    cout<<mx<<endl;
}
