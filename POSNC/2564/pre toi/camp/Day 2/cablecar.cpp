#include <bits/stdc++.h>

using namespace std;
int n,m;
struct edge{
    int u,v,w;
    bool operator<(const edge& o)const{
        return w<o.w;
    }
};
priority_queue<edge> pq;
int parent[3000];
int findset(int v){
    if(parent[v]==v)
        return v;

    return parent[v]=findset(parent[v]);
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({u,v,w});
    }
    int src,des,p; cin>>src>>des>>p;
    iota(parent+1,parent+n+1,1);
    int minedge;
    while(findset(src)!=findset(des)){
        int a = findset(pq.top().u);
        int b = findset(pq.top().v);
        minedge = pq.top().w;
        pq.pop();
        if(a==b) continue;
        parent[a]=b;
    }
    cout<<ceil(double(p)/(minedge-1));
}
