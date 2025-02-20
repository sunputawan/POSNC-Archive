#include <bits/stdc++.h>
using namespace std;
short a[20][20];
short di[] = {1,-1,0,0};
short dj[] = {0,0,-1,1};
int main(){
    short m,x,y;
    cin>>m>>x>>y;
    for(short i=0;i<m;i++){
        for(short j=0;j<m;j++)
            cin>>a[i][j];
    }
    queue<pair<short,short>> q;
    q.push({y-1,x-1});
    short mx = -5;
    while(!q.empty()){
        short i = q.front().first;
        short j = q.front().second;
        mx = max(mx,a[i][j]);
        q.pop();
        for(short k=0;k<4;k++){
            short x = i+di[k];
            short y = j+dj[k];
            if(x<0||x>=m||y<0||y>=m) continue;
            if(a[x][y]==100) continue;
            if(a[i][j]<a[x][y]){
                q.push({x,y});
            }
        }
    }
    cout<<mx<<'\n';
    return 0;
}
