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
    stack<pair<short,short>> s;
    s.push({y-1,x-1});
    short mx = -5;
    while(!s.empty()){
        short i = s.top().first;
        short j = s.top().second;
        mx = max(mx,a[i][j]);
        s.pop();
        for(short k=0;k<4;k++){
            short x = i+di[k];
            short y = j+dj[k];
            if(x<0||x>=m||y<0||y>=m) continue;
            if(a[x][y]==100) continue;
            if(a[i][j]<a[x][y]){
                s.push({x,y});
            }
        }
    }
    cout<<mx<<'\n';
    return 0;
}