#include <bits/stdc++.h>

using namespace std;
int m,n,mx,mn = INT_MAX;
char arr[70][70];
int qs[70][70];
int di[]={0,0,-1,1};
int dj[]={1,-1,0,0};
void reset(void){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]=='p')
                arr[i][j] = 'P';
        }
    }
}
int play(int x,int y){
    int cnt = 0;
    for(int i=x;i<=x+mx-1;i++){
        for(int j=y;j<=y+mx-1;j++){
            if(arr[i][j]!='P') continue;

            queue<pair<int,int> > q;
            q.push(make_pair(i,j));
            cnt++;
            while(!q.empty()){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int aa = a+di[k];
                    int bb = b+dj[k];
                    if(aa<1||aa>m||bb<1||bb>n) continue;
                    if(arr[aa][bb]!='P') continue;
                    arr[aa][bb] = 'p';
                    q.push(make_pair(aa,bb));
                }
            }
        }
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]=='T') continue;
            qs[i][j] = min(min(qs[i-1][j],qs[i][j-1]),qs[i-1][j-1])+1;
            mx = max(mx,qs[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(qs[i][j] == mx){
                reset();
                mn = min(mn,play(i-mx+1,j-mx+1));
            }
        }
    }
    cout<<mx*mx<<' ';
    if(mn == INT_MAX) cout<<0<<'\n';
    else cout<<mn<<'\n';

    return 0;
}