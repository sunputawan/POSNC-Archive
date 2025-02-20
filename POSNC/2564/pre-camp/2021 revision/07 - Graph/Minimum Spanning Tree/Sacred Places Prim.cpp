#include <bits/stdc++.h>
#define N 200001

using namespace std;
vector<vector<pair<int,int>>> adj(N);
int m,n;
int d[N]={};
long long cost=0;
int prim(void){
    priority_queue<pair<int,int>> s;
    bool in_MST[N];
    for(int i=1;i<=n;i++)
        in_MST[i] = false;
    s.push({1,1});
    while(!s.empty()){
        int u = s.top().second;
        int w = s.top().first;
        s.pop();
        if(in_MST[u])
            continue;
        in_MST[u]=true;
        cost+=w-1;
        for(int i=0;i<adj[u].size();i++){
            if(!in_MST[adj[u][i].second]){
                s.push({adj[u][i].first,adj[u][i].second});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,e;
        cin>>u>>v>>e;
        adj[u].push_back({e,v});
        adj[v].push_back({e,u});
    }
    prim();
    cout<<cost;
}
