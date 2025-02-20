#include <bits/stdc++.h>

using namespace std;
char a[50][50];
int visited[50][50];
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    while(k--){
        int sx,sy,tx,ty,l; cin>>sx>>sy>>tx>>ty>>l;
        memset(visited,0,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({sx,sy});
        bool found = false;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x==tx&&y==ty){
                found = true;
                break;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int xx = x+di[i];
                int yy = y+dj[i];
                if(xx<1||xx>n||yy<1||yy>m) continue;
                if(xx<sx-l||xx>sx+l) continue;
                if(a[xx][yy] == '#') continue;
                if(visited[xx][yy]) continue;
                visited[xx][yy] = true;
                q.push({xx,yy});
            }
        }
        cout<<(found) ? 1:0;
        cout<<'\n';
    }

    return 0;
}