#include <bits/stdc++.h>
#define INTMAX 1e9+5

using namespace std;
vector<pair<int,int>> adj[10005];
int dsrc[10005];
int ddes[10005];
int main(){
    int n,m,src,des,bud;
    cin>>n>>m>>src>>des>>bud;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0;i<n;i++){
        dsrc[i] = INTMAX;
        ddes[i] = INTMAX;
    }
    set<pair<int,int>> s;
    dsrc[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());

        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(dsrc[u]+w<=bud&&dsrc[v]>dsrc[u]+w){
                s.erase({dsrc[v],v});
                dsrc[v] = dsrc[u]+w;
                s.insert({dsrc[v],v});
            }
        }
    }
    if(dsrc[des]!=INTMAX){
        cout<<des<<' '<<dsrc[des]<<" 0\n";
        return 0;
    }
    ddes[des] = 0;
    s.insert({0,des});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());

        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(ddes[v]>ddes[u]+w){
                s.erase({ddes[v],v});
                ddes[v] = ddes[u]+w;
                s.insert({ddes[v],v});
            }
        }
    }
    int mndis = INTMAX;
    int idx;
    for(int i=0;i<n;i++){
        if(dsrc[i]!=INTMAX&&mndis>ddes[i]){
            mndis = ddes[i];
            idx = i;
        }
    }
    cout<<idx<<' '<<dsrc[idx]<<' '<<ddes[idx]<<'\n';
    return 0;
}
