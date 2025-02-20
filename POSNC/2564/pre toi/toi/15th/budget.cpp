#include <iostream>
#include <queue>

using namespace std;
int n,m,p;
int cost[1000001]={};
int parent[4000];
int si[4000];
int findset(int u){
    if(parent[u]==u)
        return u;
    return findset(parent[u]);
}
struct edge{
    int u,v,w;
    bool operator<(const edge &o)const{
        return o.w<=w;
    }
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        parent[i] = i;
        si[i] = 1;
    }
    priority_queue<edge> pq;
    for(int i=0;i<m;i++){
        int u,v,w,r;
        cin>>u>>v>>w>>r;
        if(r){
            n--;
            u = findset(u);
            v =  findset(v);
            parent[v]=u;
            /*if(si[u]>si[v]){
                parent[v] = u;
                si[u]+=si[v];
            }
            else{
                parent[u] = v;
                si[v]+=si[u];
            }*/
        }
        else{
            pq.push({u,v,w});
        }
    }
    cin>>p;
    int maxdis = 0;
    for(int i=0;i<p;i++){
        int d,c; cin>>d>>c;
        cost[d] = c;
        maxdis = max(d,maxdis);
    }
    int ref = cost[maxdis];
    for(int i=maxdis;i>=1;i--){
        if(cost[i]!=0&&ref>cost[i])
            ref = cost[i];
        else
            cost[i] = ref;
    }
    long long int total = 0;
    while(n&&!pq.empty()){
        int a = pq.top().u;
        int b = pq.top().v;
        int c = pq.top().w;
        int atmp = a;
        int btmp = b;
        pq.pop();
        a = findset(a);
        b = findset(b);
        if(a==b) continue;
        //n--;
        parent[a] = b;
        /*if(si[a]>si[b]){
            parent[b] = a;
            si[a]+=si[b];
        }
        else{
            parent[a] = b;
            si[b]+=si[a];
        }*/
        total+=cost[c];
    }
    cout<<total;
}
