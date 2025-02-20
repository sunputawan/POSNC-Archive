#include <bits/stdc++.h>

using namespace std;
int n,q;
unordered_map<int,int> cl; // student class
unordered_map<int,int> rcl; //class , represent student
vector<pair<int,int>> adj[100005];
int W,cnt,inclass;
void dfs(int u,int p,int cla){
    //cout<<"u : "<<u<<' '<<cl[u]<<endl;
    if(cl[u]==cla)
        inclass++;
    for(auto x:adj[u]){
        if(x.first==p||x.second>W) continue;
        if(cl[x.first]!=cla)
            cnt++;
        dfs(x.first,u,cla);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        cl[i] = x;
        if(!rcl[x])
            rcl[x] = i;
    }
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    while(q--){
        cin>>W;
        int ans = 0;
        for(auto x:rcl){
            cnt = 0,inclass = 0;
            dfs(x.second,0,x.first);
            cout<<"class : "<<x.first<<" : "<<cnt<<','<<inclass<<endl;
            ans += cnt*inclass;
        }
        cout<<"ans : "<<ans<<endl;
    }
}
