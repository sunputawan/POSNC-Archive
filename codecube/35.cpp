#include <bits/stdc++.h>

using namespace std;
long long n,m,st,ans,mxdis = 0;;
long long v[100005],d[100005];
vector<vector<int>> g(100005);
vector<vector<int>> dis(100005);
priority_queue<int> pq;
int main(){
    cin>>n>>m>>st;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        d[i] = INT_MAX;
    }
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pair<int,long long>> q;
    d[st] = 0;
    q.push({st,d[st]});
    while(!q.empty()){
        int u = q.front().first;
        q.pop();
        for(auto v:g[u]){
            if(d[v]!=INT_MAX) continue;
            d[v] = d[u]+1;
            mxdis = max(mxdis,d[v]);
            q.push({v,d[v]});
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]<=0) continue;
        if(d[i]!=INT_MAX)
            dis[d[i]].push_back(v[i]);
        else{
            ans += v[i];
        }

    }
    for(int i=mxdis;i>0;i--){
        for(auto cost:dis[i]){
            pq.push(cost);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';

    return 0;
}