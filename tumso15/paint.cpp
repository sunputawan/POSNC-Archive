#include <bits/stdc++.h>

using namespace std;
char a[1005][1005];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int cnt = 0;
int main(){
    int n,m; cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='*') continue;
            a[i][j] = '*';
            cnt++;
            queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int xx = x+di[k];
                    int yy = y+dj[k];
                    if(xx<1||xx>m||yy<1||yy>n) continue;
                    if(a[xx][yy] == '*') continue;
                    a[xx][yy] = '*';
                    q.push({xx,yy});
                }
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}
/*
6 8
*.......
.**.....
...**...
.....***
........
........
*/