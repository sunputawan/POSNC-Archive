#include <bits/stdc++.h>

using namespace std;
int r,c;
char a[55][55];
int dist[55][55];
int di[] = {0,0,1,-1};
int dj[] = {-1,1,0,0};
/*
3 3
D.*
...
.S.
*/
void print(void){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int sx,sy,dx,dy;
    cin>>r>>c;
    queue<pair<int,int>> q;
    queue<pair<int,int>> tmp;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
            if(a[i][j]=='*')
                tmp.push({i,j});
            if(a[i][j]=='S'){
                sx = i;
                sy = j;
            }
        }
    }

    q.push({sx,sy});
    while(!tmp.empty()){
        q.push(tmp.front());
        tmp.pop();
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int xx = x+di[i];
            int yy = y+dj[i];

            if(xx<1||xx>r||yy<1||yy>c) continue;
            if(a[xx][yy]=='X') continue;
            if(a[x][y]=='*'){
                if(a[xx][yy]=='D'||a[xx][yy]=='*') continue;
                a[xx][yy] = '*';
                dist[xx][yy] = 0;
            }
            else{
                if(a[xx][yy]=='D'){
                    cout<<dist[x][y]+1<<endl;
                    return 0;
                }
                if(a[xx-1][yy]=='*'||a[xx+1][yy]=='*'||a[xx][yy-1]=='*'||a[xx][yy+1]=='*')
                    continue;
                if(a[xx][yy]=='*') continue;
                if(dist[xx][yy]) continue;
                dist[xx][yy] = dist[x][y]+1;
                a[xx][yy] = 'S';
            }
            q.push({xx,yy});
        }
    }
    cout<<"KAKTUS\n";
    return 0;
}
