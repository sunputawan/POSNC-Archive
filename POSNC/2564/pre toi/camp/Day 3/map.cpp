#include <bits/stdc++.h>

using namespace std;
int m,n;
int u[40005],l[40005],r[40005],d[40005];
int ans[405][405];
void dfs(int cur,int i,int j){
    ans[i][j] = cur;
    if(u[cur]!=-1&&ans[i-1][j]==-1){
        dfs(u[cur],i-1,j);
    }
    if(l[cur]!=-1&&ans[i][j-1]==-1){
        dfs(l[cur],i,j-1);
    }
    if(r[cur]!=-1&&ans[i][j+1]==-1){
        dfs(r[cur],i,j+1);
    }
    if(d[cur]!=-1&&ans[i+1][j]==-1){
        dfs(d[cur],i+1,j);
    }
    return;
}
int main(){
    int a,b; char c;
    cin>>m>>n;
    memset(u,-1,sizeof(u));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    memset(d,-1,sizeof(d));
    memset(ans,-1,sizeof(ans));

    for(int i=0;i<m*n-1;i++){
        cin>>a>>c>>b;
        if(c=='U'){
            u[b]=a;
            d[a]=b;
        }
        else{
            l[b]=a;
            r[a]=b;
        }
    }

    dfs(0,m,n);
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            if(ans[i][j]==-1) continue;
            for(int ii=i;ii<i+m;ii++){
                for(int jj=j;jj<j+n;jj++){
                    cout<<ans[ii][jj]<<" ";
                }
                cout<<endl;
            }
            return 0;
        }
    }
    return 0;
}
