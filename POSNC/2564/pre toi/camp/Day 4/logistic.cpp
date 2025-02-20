#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> adj[105];
int a[105];
int cost[105][105][2];
struct A{
    int u,c,f,card;
    bool operator<(const A&o)const{
        return c>o.c;
    }
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int src,des,lim,m;
    cin>>src>>des>>lim>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<A> pq;
    memset(cost,127,sizeof cost);
    cost[src][0][1] = 0;
    pq.push({src,0,0,1});
    while(!pq.empty()){
        int u = pq.top().u;
        int c = pq.top().c;
        int f = pq.top().f;
        int card = pq.top().card;
        //cout<<u<<" "<<c<<" "<<f<<" "<<card<<endl;
        pq.pop();
        if(u==des&&f==lim){
            cout<<c<<endl;
            return 0;
        }

        if(f<lim&&card&&c<cost[u][lim][0]){
            cost[u][lim][0] = c;
            pq.push({u,c,lim,0});
        }
        if(f<lim&&c+a[u]<cost[u][f+1][card]){
            cost[u][f+1][card] = c+a[u];
            pq.push({u,c+a[u],f+1,card});
        }
        for(auto x:adj[u]){
            if(f<x.second) continue;

            if(c<cost[x.first][f-x.second][card]){
                cost[x.first][f-x.second][card] = c;
                pq.push({x.first,c,f-x.second,card});
            }
        }
    }
}
