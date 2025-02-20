#include <bits/stdc++.h>

using namespace std;
char a[2005][2005];
bool visited[2005][2005];
int n,m;
struct coor{
    int x,y,cnt;
};
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    queue<coor> q;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='X')
                q.push({i,j,0});
        }
    }
    int totaldis=0;
    int count=0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        if(x<0||x>=n||y<0||y>=m) continue;
        if(visited[x][y]) continue;
        visited[x][y]=true;

        if(a[x][y]=='W') continue;
        if(a[x][y]=='A'){
            count++;
            totaldis+=cnt;
        }
        for(auto d:dir){
            q.push({x+d.first,y+d.second,cnt+1});
        }
    }
    cout<<count<<" "<<totaldis*2;
}
