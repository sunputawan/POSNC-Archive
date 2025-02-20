#include <bits/stdc++.h>

using namespace std;
int n,m;
int parent[3005];
int findset(int v){
    if(parent[v]==v)
        return v;
    return parent[v] = findset(parent[v]);
}
struct edge{
    int u,v,w;
    bool operator<(const edge &o)const{
        return w>=o.w;
    }
};
int cost[1000005];
priority_queue<edge> pq;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        parent[i]=i;
    for(int i=0;i<m;i++){
        int s,t,l; cin>>s>>t>>l;
        int r; cin>>r;
        if(r){
            s = findset(s);
            t = findset(t);
            parent[s] = t;
        }
        else{
            pq.push({s,t,l});
        }
    }
    int p; cin>>p;
    int maxdis = 0;
    for(int i=0;i<p;i++){
        int c,d; cin>>d>>c;
        cost[d]=c;
        maxdis = max(maxdis,d);
    }
    for(int i=maxdis-1;i>0;i--){
        if(cost[i]==0)
            cost[i]=cost[i+1];
        else
            cost[i] = min(cost[i],cost[i+1]);
    }
    long long totalcost = 0;
    while(!pq.empty()){
        int a = findset(pq.top().u);
        int b = findset(pq.top().v);
        int d = pq.top().w;
        pq.pop();
        if(a==b) continue;
        parent[a]=b;
        totalcost+=cost[d];
    }
    cout<<totalcost<<endl;
    return 0;
}
