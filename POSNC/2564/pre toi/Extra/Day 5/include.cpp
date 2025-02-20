#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
unordered_set<int> s;
int n;
int child[1001];
int visited[1001];
int dfs(int u){
    bool rep = false;
    for(int v:adj[u]){
        if(visited[v]) return 1;
        visited[v] = 1;
        rep |= dfs(v);
    }
    return rep;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        while(k--){
            int x; cin>>x;
            adj[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
