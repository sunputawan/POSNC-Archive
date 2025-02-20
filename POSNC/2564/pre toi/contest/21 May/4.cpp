#include <bits/stdc++.h>

using namespace std;
struct A{
    int u,d,x;
};
struct B{
    int u,d,x;
    bool operator<(const B&o)const{
        return d>o.d;
    }
};
vector<A> adj[10001];
int path[10001][(1<<8)];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,src,q;
    cin>>n>>m>>src>>q;
    while(m--){
        int u,v,w,x;
        cin>>u>>v>>w>>x;
        adj[u].push_back({v,w,x});
        adj[v].push_back({u,w,x});
    }

    memset(path,127,sizeof path);

    priority_queue<B> pq;
    path[src][0] = 0;
    pq.push({src,0,0});
    while(!pq.empty()){
        int u = pq.top().u;
        int d = pq.top().d;
        int cur = pq.top().x;
        pq.pop();

        for(auto x:adj[u]){
            int v = x.u;
            int w = x.d;
            int bit = cur|(1<<(x.x-1));

            if(d+w<path[v][bit]){
                path[v][bit] = d+w;
                pq.push({v,d+w,bit});
            }
        }
    }
    while(q--){
        int bit = (1<<8)-1;
        int des,k;
        cin>>des>>k;
        while(k--){
            int x; cin>>x;
            bit ^= (1<<(x-1));
        }
        int mn = INT_MAX;
        for(int i=0;i<(1<<8);i++){
            if((bit&i)==i){
                mn = min(mn,path[des][i]);
            }
        }
        if(mn>1e8)
            cout<<-1<<endl;
        else
            cout<<mn<<endl;
    }
}
