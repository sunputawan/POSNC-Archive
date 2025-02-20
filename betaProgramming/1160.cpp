#include <bits/stdc++.h>
#define INTMAX 9999999
using namespace std;
int a[200][200];
int ds[200][200];
int de[200][200];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int main(){
    int m,n,sx,sy,ex,ey; cin>>m>>n>>sx>>sy>>ex>>ey;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            ds[i][j] = INTMAX;
            de[i][j] = INTMAX;
        }
    }
    ds[sx][sy] = 1;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int xx = x+di[k];
            int yy = y+dj[k];
            if(xx<1||xx>m||yy<1||yy>n) continue;
            if(a[xx][yy] == 0) continue;
            if(ds[xx][yy]>ds[x][y]+1){
                ds[xx][yy] = ds[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
    de[ex][ey] = 1;
    q.push({ex,ey});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int xx = x+di[k];
            int yy = y+dj[k];
            if(xx<1||xx>m||yy<1||yy>n) continue;
            if(a[xx][yy] == 0) continue;
            if(de[xx][yy]>de[x][y]+1){
                de[xx][yy] = de[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
    cout<<'\n';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ds[i][j]==INTMAX) cout<<'-'<<' ';
            else cout<<ds[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(de[i][j]==INTMAX) cout<<'-'<<' ';
            else cout<<de[i][j]<<' ';
        }
        cout<<'\n';
    }
    int cntbomb = 0,mndis = INTMAX;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(a[i][j]==1) continue;
            int mns = INTMAX;
            int mne = INTMAX;
            for(int k=0;k<4;k++){
                int ii = i+di[k];
                int jj = j+dj[k];
                if(ii<1||ii>m||jj<1||jj>n) continue;
                if(ds[ii][jj]!=INTMAX) mns = min(mns,ds[ii][jj]); 
            }
            for(int k=0;k<4;k++){
                int ii = i+di[k];
                int jj = j+dj[k];
                if(ii<1||ii>m||jj<1||jj>n) continue;
                if(de[ii][jj]!=INTMAX) mne = min(mne,de[ii][jj]); 
            }
            if(mns!=INTMAX && mne != INTMAX){
                cntbomb++;
                mndis = min(mndis,mns+mne+1);
            }
        }
    }

    cout<<cntbomb<<'\n'<<mndis<<'\n';

    return 0;
}