#include <bits/stdc++.h>

using namespace std;
int r,c;
char a[1005][1005];
int mark[1005][1005];
int visited[1005][1005];
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
/*
5 5
.....
..X..
.X.X.
..X..
.....
*/
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        int x = q.front().first;
        int y =  q.front().second;
        q.pop();
        if(x<1||x>r||y<1||y>c) continue;
        if(mark[x][y]) continue;
        if(a[x][y]!='.') continue;
        mark[x][y] = 1;
        for(auto d:dir){
            q.push({x+d.first,y+d.second});
        }
    }

    int mx=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]=='.') continue;
            int cnt=0;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x<1||x>r||y<1||y>c) continue;
                if(visited[x][y]) continue;
                if(a[x][y]!='X') continue;
                a[x][y]='.';
                visited[x][y]=1;
                if(mark[x-1][y]) cnt++;
                if(mark[x][y-1]) cnt++;
                if(mark[x+1][y]) cnt++;
                if(mark[x][y+1]) cnt++;

                for(auto d:dir){
                    q.push({x+d.first,y+d.second});
                }
            }
            mx = max(cnt,mx);
        }
    }
    cout<<mx<<endl;
    return 0;
}
