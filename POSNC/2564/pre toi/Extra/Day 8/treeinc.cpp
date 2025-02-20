#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> adj[300005];
int dp[300005];
/*
9
1 2
2 9
1 7
6 8
2 6
3 9
4 9
5 4
*/
void dfs1(int u,int p){
    for(int v:adj[u]){
        if(v==p||u>v) continue;
        //cout<<u<<"->"<<v<<endl;
        dfs1(v,u);
        dp[u] = max(dp[u],dp[v]+1);
    }
}
void dfs2(int u,int p){
    for(int v:adj[u]){
        if(v==p) continue;
        if(u>v){
            //cout<<u<<"->"<<v<<endl;
            dp[v] += dp[u];
        }
        dfs2(v,u);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        dp[i] = 1;
    dfs1(1,0);
    dfs2(1,0);
    int mx = 0;
    for(int i=1;i<=n;i++)
        mx = max(mx,dp[i]);
    cout<<mx<<endl;
    return 0;
}
