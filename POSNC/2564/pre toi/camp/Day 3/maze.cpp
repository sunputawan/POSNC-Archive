#include <bits/stdc++.h>
#define INTMAX 500000

using namespace std;
struct coor{
    int x,y,dis;
};
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int r,c,sx,sy,tx,ty;
int a[155][155];
int distsrc[155][155];
int distdes[155][155];
int main(){
    cin>>r>>c;
    cin>>sx>>sy>>tx>>ty;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    memset(distsrc,-1,sizeof(distsrc));
    memset(distdes,-1,sizeof(distdes));

    queue<coor> q;
    q.push({sx,sy,1});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dis = q.front().dis;
        q.pop();
        if(x<1||x>r||y<1||y>c) continue;
        if(distsrc[x][y]!=-1) continue;
        distsrc[x][y] = dis;
        if(a[x][y]==0) continue;
        for(auto d:dir){
            q.push({x+d.first,y+d.second,dis+1});
        }
    }
    q.push({tx,ty,1});
    int cnt = 0;
    int mindis = 2e9;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dis = q.front().dis;
        q.pop();
        if(x<1||x>r||y<1||y>c) continue;
        if(distdes[x][y]!=-1) continue;
        distdes[x][y] = dis;
        if(a[x][y]==0){
            if(distsrc[x][y]!=-1){
                cnt++;
                mindis = min(mindis,distsrc[x][y]+distdes[x][y]);
            }
            continue;
        }
        for(auto d:dir){
            q.push({x+d.first,y+d.second,dis+1});
        }
    }
    cout<<cnt<<'\n'<<mindis-1<<'\n';
    return 0;
}
