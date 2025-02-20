#include <bits/stdc++.h>

using namespace std;
int m,n;
double a[5][5];
int visited[5][5];
double mn = 1000000000;
int di[] = {0,0,1,1,1,-1,-1,-1};
int dj[] = {-1,1,-1,0,1,-1,0,1};
void buy(int round,int x,int y,double cost){
    visited[x][y] = 1;
    if(round==m*n){
        mn = min(cost+a[x][y],mn);
    }
    for(int i=0;i<8;i++){
        int xx = di[i]+x;
        int yy = dj[i]+y;
        a[xx][yy] += a[x][y]/10;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j]) continue;
            buy(round+1,i,j,cost+a[x][y]);
        }
    }
    for(int i=0;i<8;i++){
        int xx = di[i]+x;
        int yy = dj[i]+y;
        a[xx][yy] -= a[x][y]/10;
    }
    visited[x][y] = 0;
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            memset(visited,0,sizeof(visited));
            buy(1,i,j,0);
        }
    }
    printf("%.2f\n",mn);
}
