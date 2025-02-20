#include <bits/stdc++.h>
char w[2005][2005];
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    queue<pair<int,int>> q;
    int di[8][2] = {
      {1, 0}, {-1, 0}, {0, 1},  {0, -1},
      {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(w[i][j]=='1')
                ans++;
            q.push({i,j});
            while(!q.empty()){
                auto f=q.front();
                q.pop();
                int x=f.first;
                int y=f.second;
                if(w[x][y]=='0')
                    continue;
                w[x][y]='0';
                for(int k=0;k<8;k++){
                    int xx=x+di[k][0];
                    int yy=y+di[k][1];
                    if(xx<1||xx>m||yy<1||yy>n)
                        continue;
                    if(w[xx][yy]=='1')
                        q.push({xx,yy});
                }
            }
        }
    }
    cout<<ans;
}
