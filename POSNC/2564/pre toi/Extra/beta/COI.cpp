#include <bits/stdc++.h>

using namespace std;
char a[505][505];
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
pair<int,int> src;
struct stats{
    int x,y,cnt;
    int J,B,P;
};
int visited[505][505][2][2][2]={};
int main(){
    int m,n; cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='S')
                src = {i,j};
        }
    }

    queue<stats> q;
    q.push({src.first,src.second,0,0,0,0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int jj = q.front().J;
        int bb = q.front().B;
        int pp = q.front().P;
        q.pop();
        if(x<0||x>=m||y<0||y>=n) continue;

        if(visited[x][y][jj][bb][pp]) continue;
        visited[x][y][jj][bb][pp] = 1;

        if(a[x][y]=='#') continue;
        if(a[x][y]=='J'&&!jj) continue;
        if(a[x][y]=='B'&&!bb) continue;
        if(a[x][y]=='P'&&!pp) continue;

        if(a[x][y]=='E'){
            cout<<cnt<<'\n';
            return 0;
        }
        if(a[x][y]=='j') jj = 1;
        if(a[x][y]=='b') bb = 1;
        if(a[x][y]=='p') pp = 1;

        for(auto d:dir){
            q.push({x+d.first,y+d.second,cnt+1,jj,bb,pp});
        }
    }
    cout<<-1<<'\n';
    return 0;
}
