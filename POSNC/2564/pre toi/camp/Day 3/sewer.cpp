#include <bits/stdc++.h>

using namespace std;
int m,n;
int u[105][105],l[105][105],r[105][105],d[105][105];
int a[105][105];
int dist[105][105];
struct coor{
    int x,y;
    int prex,prey;
};
queue<coor> q;
int main(){
    cin>>m>>n;
    memset(dist,-1,sizeof(dist));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            if(c=='B'){
                u[i+1][j]=1;
                l[i][j+1]=1;
                d[i][j]=1;
                r[i][j]=1;
            }
            else if(c=='R'){
                r[i][j]=1;
                l[i][j+1]=1;
            }
            else if(c=='D'){
                d[i][j]=1;
                u[i+1][j]=1;
            }
        }
    }
    dist[0][0]=0;
    q.push({1,1,0,0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int prex =  q.front().prex;
        int prey = q.front().prey;
        q.pop();
        if(x<1||x>m||y<1||y>n) continue;
        if(dist[x][y]!=-1){
            cout<<dist[x][y]<<'\n';
            cout<<x<<" "<<y;
            return 0;
        }
        dist[x][y]=dist[prex][prey]+1;
        if(u[x][y]){
            if(x-1!=prex)
                q.push({x-1,y,x,y});
        }
        if(l[x][y]){
            if(y-1!=prey)
                q.push({x,y-1,x,y});
        }
        if(d[x][y]){
            if(x+1!=prex)
                q.push({x+1,y,x,y});
        }
        if(r[x][y]){
            if(y+1!=prey)
                q.push({x,y+1,x,y});
        }
    }
    return 0;
}
