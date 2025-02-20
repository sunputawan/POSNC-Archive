#include <bits/stdc++.h>

using namespace std;
int di[]={0,0,1,1,1,-1,-1,-1};
int dj[]={-1,1,-1,0,1,-1,0,1};
char a[2005][2005];
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    queue<pair<int,int>> q;
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='0') continue;
            q.push({i,j});
            cnt++;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x<0||x>=m||y<0||y>=n) continue;
                if(a[x][y]=='0') continue;
                a[x][y]='0';
                for(int k=0;k<8;k++){
                    int ii=x+di[k];
                    int jj=y+dj[k];
                    q.push({ii,jj});
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
