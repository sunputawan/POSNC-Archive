#include <bits/stdc++.h>

using namespace std;
int a[1005][1005],sx,sy,ex,ey;
int cost[1005][1005];
bool visited[1005][1005];
struct node{
    int x,y,d;
    bool operator<(const node &o)const{
        return d>o.d;
    }
};
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            cost[i][j] = __INT_MAX__;
            if(a[i][j]==0){
                if(sx==0)
                    sx = i, sy = j;
                else
                    ex = i, ey = j;
                
            }
        }
    }
    priority_queue<node> pq;
    pq.push({sx,sy,0});
    visited[sx][sy] = true;
    cost[sx][sy] = 0;
    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        int d = pq.top().d;
        pq.pop();
        if(x==ex && y==ey){
            cout<<d<<'\n';
            return 0;
        }
        for(int k=0;k<4;k++){
            int xx = x+di[k];
            int yy = y+dj[k];
            if(xx<1||xx>n||yy<1||yy>n) continue;
            if(visited[xx][yy]) continue;
            visited[xx][yy] = true;
            pq.push({xx,yy,max(d,a[xx][yy])});
        }
    }
}