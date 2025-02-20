#include <bits/stdc++.h>

using namespace std;
int a[21][21];
vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
struct coor{
    int x,y,prev;
};
int main(){
    int m,x,y;
    cin>>m>>x>>y;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    queue<coor> q;
    q.push({y,x,-6});
    int mx = -6;
    while(!q.empty()){
        int i = q.front().x;
        int j = q.front().y;
        int prev = q.front().prev;
        //cout<<i<<" "<<j<<endl;
        q.pop();
        if(i<1||i>m||j<1||j>m) continue;
        if(a[i][j]==100) continue;
        if(a[i][j]<=prev) continue;
        mx = max(mx,a[i][j]);
        for(auto d:dir){
            q.push({i+d.first,j+d.second,a[i][j]});
        }
    }
    cout<<mx;
    return 0;
}
