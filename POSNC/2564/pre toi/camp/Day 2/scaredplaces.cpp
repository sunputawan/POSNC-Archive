#include <bits/stdc++.h>

using namespace std;
struct edge{
    int u,v,w;
    bool operator<(const edge &o)const{
        return w<=o.w;
    }
};
int parent[200005];
int findset(int v){
    if(parent[v]==v)
        return v;
    return parent[v]=findset(parent[v]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m;
    priority_queue<edge> pq;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({u,v,w});
    }
    iota(parent+1,parent+n+1,1);
    long long cost = 0;
    while(n&&!pq.empty()){
        int a = findset(pq.top().u);
        int b = findset(pq.top().v);
        int c = pq.top().w;
        pq.pop();
        if(a==b) continue;
        n--;
        parent[a]=b;
        cost+=c-1;
    }
    cout<<cost;
}
