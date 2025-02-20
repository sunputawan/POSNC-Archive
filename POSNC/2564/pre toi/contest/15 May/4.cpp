#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int,int>> g[100005];
int dp[100005];
void dfs1(int u,int p){
    for(auto x:g[u]){
        if(x.first==p) continue;
        dfs1(x.first,u);
        dp[u]+=dp[x.first]+x.second;
    }
}
void dfs2(int u,int p){
    for(auto x:g[u]){
        if(x.first==p) continue;
        dp[x.first] = dp[u]+(x.second==1 ? -1:1);
        dfs2(x.first,u);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        g[a].push_back({b,0});
        g[b].push_back({a,1});
    }

    dfs1(1,0);
    dfs2(1,0);

    int mn = 100005;
    int idx;
    for(int i=1;i<=n;i++){
        if(mn>dp[i]){
            mn = dp[i];
            idx = i;
        }
    }
    cout<<mn<<' '<<idx<<endl;
    return 0;
}
