#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
int dp1[1005][1005];
int dp2[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};
int main(){
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]!='#'){
                dp1[i][j] = 1+min(dp1[i][j-1],dp1[i-1][j]);
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=c;j>=1;j--){
            if(a[i][j]!='#'){
                dp2[i][j] = 1+min(dp2[i][j+1],dp2[i-1][j]);
            }
        }
    }
    for(int i=r;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(a[i][j]!='#'){
                dp3[i][j] = 1+min(dp3[i][j-1],dp3[i+1][j]);
            }
        }
    }
    for(int i=r;i>=1;i--){
        for(int j=c;j>=1;j--){
            if(a[i][j]!='#'){
                dp4[i][j] = 1+min(dp4[i][j+1],dp4[i+1][j]);
            }
        }
    }
    int mx = 0;
    int x,y;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int mn1 = min(dp1[i][j],dp2[i][j]);
            int mn2 = min(dp3[i][j],dp4[i][j]);
            int mn = min(mn1,mn2);
            if(mn>mx){
                mx = mn;
                x = i,y = j;
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(abs(x-i)+abs(y-j)<mx)
                cout<<'x';
            else
                cout<<a[i][j];
        }
        cout<<'\n';
    }
}
