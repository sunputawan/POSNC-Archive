#include <bits/stdc++.h>

/*
1
3 5 4
##...
...P#
...#.
*/
/*
1
7 6 12
.##.##
......
##P.#.
#.#...
#.....
.#.#..
###...
*/
using namespace std;
char a[1000][1000];
int dist[1000][1000];
int r,c,k;
int sx,sy;
vector<pair<int,int>> dir = {{1,0},{0,-1},{0,1},{-1,0}}; //D L R U
char ans[] = {'D','L','R','U'};
void solve(){
    cin>>r>>c>>k;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            dist[i][j]=-1;
            cin>>a[i][j];
            if(a[i][j]=='P'){
                sx=i,sy=j;
                dist[i][j]=0;
            }
        }
    }
    if(k%2){
        cout<<"Can't do\n";
        return;
    }
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto d:dir){
            int xx = x+d.first;
            int yy = y+d.second;
            if(xx<0||xx>=r||yy<0||y>=c||a[xx][yy]=='#') continue;
            if(dist[xx][yy]!=-1) continue;

            dist[xx][yy] = dist[x][y]+1;
            q.push({xx,yy});
        }
    }
    /*for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%2d ",dist[i][j]);
        cout<<endl;
    }*/
    vector<char> path;
    int dis=0;
    int cnt=k;
    int x = sx,y = sy;
    while(cnt--){
        for(int i=0;i<4;i++){
            int xx = x+dir[i].first;
            int yy = y+dir[i].second;
            if(xx<0||xx>=r||yy<0||yy>=c||a[xx][yy]=='#') continue;
            if(dis+dist[xx][yy]<=k){
                x = xx, y = yy;
                dis++;
                path.push_back(ans[i]);
                break;
            }
        }
    }
    if(dis!=k){
        cout<<"Can't do\n";
    }
    else{
        for(auto i:path)
            cout<<i;
        cout<<endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin>>q;
    while(q--){
        solve();
    }
    return 0;
}
