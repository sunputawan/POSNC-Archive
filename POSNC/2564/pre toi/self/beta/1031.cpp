#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10001];
bool visited[10001];
int maxfl = 1;
int k,n,m;
int main(){
    cin>>k>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()){
        int d = q.front().first;
        int u = q.front().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(d>k) continue;
        maxfl = max(maxfl,u);
        for(auto v:adj[u]){
            q.push({d+1,v});
        }
    }
    cout<<maxfl<<endl;
    return 0;
}
