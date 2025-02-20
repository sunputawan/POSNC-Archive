#include <iostream>

using namespace std;

int dp[500][500] = {};
int hor[500][500] = {};
int ver[500][500] = {};
int solve(void){
    int m,n,t;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 1;
        }
    }
    cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        dp[a][b] = 0;
    }
    hor[0][0] = ver[0][0] = dp[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==0){
                hor[i][j] = 0;
                ver[i][j] = 0;
                continue;
            }
            if(j==0)
                hor[i][j] = 1;
            else
                hor[i][j] = hor[i][j-1]+1;
            if(i==0)
                ver[i][j] = 1;
            else
                ver[i][j] = ver[i-1][j]+1;
        }
    }
    int max = 1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            int tmp = min(hor[i][j],ver[i][j]);
            while(tmp>max){
                if(ver[i][j-tmp+1]>=tmp&&hor[i-tmp+1][j]>=tmp){
                    max=tmp;
                }
                tmp--;
            }
        }
    }
    return max;
}
int main(){
    int a = solve();
    int b = solve();
    cout<<a<<endl<<b;
}
