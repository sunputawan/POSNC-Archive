#include <bits/stdc++.h>

using namespace std;
int a[105][105];
int visited[105][105];
int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    queue<pair<int,int>> q;
    while(k--){
        memset(visited,0,sizeof(visited));
        int sx,sy; cin>>sy>>sx;
        q.push({sx,sy});
        char d;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x<1||x>m||y<1||y>n){
                cout<<d<<endl;
                break;
            }
            if(visited[x][y]){
                cout<<"NO\n";
                break;
            }
            visited[x][y] = 1;
            if(a[x][y]==1){
                d = 'N';
                q.push({x-1,y});
            }
            else if(a[x][y]==2){
                d = 'E';
                q.push({x,y+1});
            }
            else if(a[x][y]==3){
                d = 'S';
                q.push({x+1,y});
            }
            else if(a[x][y]==4){
                d = 'W';
                q.push({x,y-1});
            }
        }
        while(!q.empty())
            q.pop();
    }
    return 0;
}
