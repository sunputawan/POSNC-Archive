#include <bits/stdc++.h>

using namespace std;
char a[50][50];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int mx = 0;
int main(){
    int m,n; cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!='#') continue;
            for(int k=0;k<4;k++){
                int ii = i+di[k];
                int jj = j+dj[k];
                if(a[ii][jj]=='#') continue;
                a[ii][jj] = '-';
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!='.') continue;
            int cnt = 1;
            stack<pair<int,int>> s;
            a[i][j] = '@';
            s.push({i,j});
            while(!s.empty()){
                int x = s.top().first;
                int y = s.top().second;
                s.pop();
                for(int k=0;k<4;k++){
                    int xx = x+di[k];
                    int yy = y+dj[k];
                    if(xx<1||xx>m||yy<1||yy>n) continue;
                    if(a[xx][yy]!='.') continue;
                    a[xx][yy] = '@';
                    cnt++;
                    s.push({xx,yy});
                }
            }
            mx = max(mx,cnt);
        }
    }

    cout<<mx<<'\n';
}