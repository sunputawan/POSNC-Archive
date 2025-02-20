#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> adj[2005];
vector<pair<int,int>> track[2005];
struct A{
    int u,d,cnt;
    bool operator<(const A&o)const{
        return d>=o.d;
    }
};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,src,des,m;
    cin>>n>>src>>des>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    priority_queue<A> pq;
    pq.push({src,0,0});
    while(!pq.empty()){
        int u = pq.top().u;
        int d = pq.top().d;
        int cnt = pq.top().cnt;
        pq.pop();
        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            bool add = true;
            for(auto p:track[v]){
                if(p.first<=d+w && p.second<cnt){
                    add = false;
                    break;
                }
            }
            if(add){
                pq.push({v,d+w,cnt+1});
                track[v].push_back({d+w,cnt+1});
            }
        }
    }
    int l;
    cin>>l;
    while(l--){
        int h,mn = 1e9+5;
        cin>>h;
        for(auto x:track[des]){
            mn = min(mn,x.first+(x.second-1)*h);
        }
        cout<<mn<<' ';
    }
}
