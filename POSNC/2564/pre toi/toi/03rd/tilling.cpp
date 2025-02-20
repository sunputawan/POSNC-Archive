#include <bits/stdc++.h>

using namespace std;
int n;
int a[20][20];
void print(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0) continue;
            //print();
            int ref = a[i][j];
            int cnt = 0;
            queue<pair<int,int>> q;
            q.push({i,j});
            int bx=0,by=0;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x<0||x>=n||y<0||y>=n) continue;
                if(a[x][y]==ref){
                    bx = max(bx,abs(i-x));
                    by = max(bx,abs(j-y));
                    cnt++;
                    a[x][y] = 0;
                    for(auto d:dir)
                        q.push({x+d.first,y+d.second});
                }
            }
            if(cnt==3&&bx==1&&by==1)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
