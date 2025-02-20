#include <bits/stdc++.h>
#define INTMAX 1000000
using namespace std;
vector<pair<int,int>> adj[100005];
struct stats{
    int u,mn,mx,dif;
    bool operator<(const stats &o)const{
        return dif<=o.dif;
    }
};
bool visited[100005];
set<stats> s;
int d[100005];
int curmn,curmx;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,src,des;
    cin>>n>>m>>src>>des;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        d[i]=INTMAX;
    visited[src] = 1;
    for(auto v:adj[src]){
        d[v.first] = 0;
        s.insert({v.first,v.second,v.second,0});
    }
    while(!s.empty()){
        int u = s.begin()->u;
        int mn = s.begin()->mn;
        int mx = s.begin()->mx;
        s.erase(s.begin());
        //cout<<"operating : "<<u<<" "<<mn<<" "<<mx<<" "<<d[u]<<endl;
        if(u==des){
            cout<<d[des]<<endl;
            return 0;
        }
        visited[u] = 1;
        for(auto vpair:adj[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(visited[v]) continue;

            int difplus;
            curmn = min(mn,w);
            curmx = max(mx,w);

            if(d[v]>curmx-curmn){
                d[v] = curmx-curmn;
                s.insert({v,curmn,curmx,d[v]});
            }
        }
    }
}
