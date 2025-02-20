#include <bits/stdc++.h>

using namespace std;
int n,k;
vector<pair<int,int>> h;
int distance(int i,int j){
    return abs(h[i].first-h[j].first)+abs(h[i].second-h[j].second);
}
int dist[15005];
int visited[15005];
priority_queue<int> pq;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        h.push_back({a,b});
    }
    memset(dist,500005,sizeof(dist));
    int pre=0;
    for(int i=0;i<n;i++){
        int u = pre;
        int curmindis = 500005;
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(visited[v]) continue;
            int dis = distance(u,v);
            dist[v] = min(dist[v],dis);
            if(curmindis>dist[v]){
                curmindis = dist[v];
                pre = v;
            }
        }
        pq.push(curmindis);
    }
    while(k--)
        pq.pop();
    int cost = 0;
    while(!pq.empty()){
        cost+=pq.top();
        pq.pop();
    }
    cout<<cost<<endl;
}
