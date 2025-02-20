#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> g[105][105];
int dis[105][105];
struct node{
    int x,y,prex,prey;
};
int main(){
    int m,n; cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            if(c=='B'){
                g[i][j].push_back({i,j+1});
                g[i][j+1].push_back({i,j});
                g[i][j].push_back({i+1,j});
                g[i+1][j].push_back({i,j});

            }
            if(c=='D'){
                g[i][j].push_back({i+1,j});
                g[i+1][j].push_back({i,j});
            }
            if(c=='R'){
                g[i][j].push_back({i,j+1});
                g[i][j+1].push_back({i,j});
            }
        }
    }

    queue<node> q;
    q.push({1,1,0,0});
    dis[1][1] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int prex = q.front().prex;
        int prey = q.front().prey;
        //cout<<x<<' '<<y<<'\n';
        q.pop();
        for(pair<int,int> p:g[x][y]){
            int xx = p.first;
            int yy = p.second;
            if(xx == prex && yy == prey) continue;
            if(dis[xx][yy]){
                cout<<dis[xx][yy]<<'\n'<<xx<<' '<<yy<<'\n';
                return 0;
            }
            dis[xx][yy] = dis[x][y]+1;
            q.push({xx,yy,x,y});
        }
    }
}