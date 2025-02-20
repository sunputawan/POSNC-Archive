#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int dp0[256][256];
int dp1[256][256];
int dp2[256][256];
int main(){
    int q=20;
    while(q--){
        memset(dp0,0,sizeof dp0);
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);

        cin>>n>>s;
        s = ' '+s;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')
                dp0[i][i]++;
            else if(s[i]=='1')
                dp1[i][i]++;
            else if(s[i]=='2')
                dp2[i][i]++;
        }

        for(int k=2;k<=n;k++){
            for(int i=1;i<=n-k+1;i++){
                int j = i+k-1;
                for(int l=i;l<j;l++){
                    if(dp0[i][l]&&dp0[l+1][j])
                        dp2[i][j] = 1;
                    if(dp0[i][l]&&dp1[l+1][j])
                        dp1[i][j] = 1;
                    if(dp0[i][l]&&dp2[l+1][j])
                        dp0[i][j] = 1;

                    if(dp1[i][l]&&dp0[l+1][j])
                        dp2[i][j] = 1;
                    if(dp1[i][l]&&dp1[l+1][j])
                        dp1[i][j] = 1;
                    if(dp1[i][l]&&dp2[l+1][j])
                        dp1[i][j] = 1;

                    if(dp2[i][l]&&dp0[l+1][j])
                        dp1[i][j] = 1;
                    if(dp2[i][l]&&dp1[l+1][j])
                        dp2[i][j] = 1;
                    if(dp2[i][l]&&dp2[l+1][j])
                        dp1[i][j] = 1;
                }
            }
        }
        if(dp0[1][n])
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
