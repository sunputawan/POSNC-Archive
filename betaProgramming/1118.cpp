#include <bits/stdc++.h>

using namespace std;
int n;
int sw[20][20],target[20][20];
bool pressed[20][20];
vector<pair<int,int>> cur;
vector<pair<int,int>> ans;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
void recur(int x,int y){
    if(x>n){
        bool same = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sw[i][j]!=target[i][j]){
                    same = false;
                    break;
                }
            }
        }
        if(same){
            ans = cur;
        }
        return;
    }

    int nextx = x, nexty = y+1;
    if(y==n){
        nextx = x+1;
        nexty = 1;
    }
    
    recur(nextx,nexty);

    cur.push_back({x,y});
    sw[x][y] = 1-sw[x][y];
    for(int k=0;k<4;k++){
        int xx = x+di[k];
        int yy = y+dj[k];
        sw[xx][yy] = 1-sw[xx][yy];
    }
    recur(nextx,nexty);
    for(int k=0;k<4;k++){
        int xx = x+di[k];
        int yy = y+dj[k];
        sw[xx][yy] = 1-sw[xx][yy];
    }
    sw[x][y] = 1-sw[x][y];
    cur.pop_back();
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>sw[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>target[i][j];
        }
    }

    recur(1,1);

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }

    return 0;
}