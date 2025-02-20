#include <bits/stdc++.h>

using namespace std;
int n,m,p;
int g[505][505];
int mark[505];
int dist[505][3];
int idx[505][3];
int a[505];

int main(){
    int q; cin>>q;
    while(q--){
        cin>>n>>m>>p;
        memset(mark,0,sizeof mark);
        memset(dist,-1,sizeof dist);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                g[i][j] = 1e9;
        }
        for(int i=1;i<=n;i++)
            g[i][i] = 0;
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            g[u][v] =  min(g[u][v],w);
            g[v][u] = min(g[v][u],w);
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        for(int i=0;i<p;i++){
            cin>>a[i];
            mark[a[i]] = 1;
        }

        for(int i=1;i<=n;i++){
            if(!mark[i]) continue;
            for(int j=1;j<=n;j++){
                if(!mark[j]||i==j) continue;

                if(dist[i][1]==-1||g[i][j]<dist[i][1]){
                    dist[i][3] = dist[i][2];
                    dist[i][2] = dist[i][1];
                    dist[i][1] = g[i][j];
                    idx[i][1] = j;
                }
                else if(dist[i][2]==-1||g[i][j]<dist[i][2]){
                    dist[i][3] = dist[i][2];
                    dist[i][2] = g[i][j];
                    idx[i][2] = j;
                }
                else if(dist[i][3]==-1||g[i][j]<dist[i][3]){
                    dist[i][3] = g[i][j];
                    idx[i][3] = j;
                }
            }
        }
        int ans = INT_MAX;
        for(int ii=0;ii<p;ii++){
            for(int jj=0;jj<p;jj++){
                int i = a[ii],j=a[jj];
                if(i==j||g[i][j]>=1e9) continue;
                for(int kk=0;kk<p;kk++){
                    int k = a[kk];
                    if(k==i||k==j) continue;
                    if(idx[k][1]!=i&&idx[k][1]!=j&&dist[k][1]!=-1)
                        ans = min(ans,g[i][j]+dist[k][1]);
                    else if(idx[k][2]!=i && idx[k][2]!=j && dist[k][2]!=-1)
                        ans = min(ans,g[i][j]+dist[k][2]);
                    else if(idx[k][3]!=i && idx[k][3]!=j && dist[k][3]!=-1)
                        ans = min(ans,g[i][j]+dist[k][3]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
