#include <iostream>
#include <vector>


using namespace std;
vector<vector<int>> adj;
bool visited[500001];
bool in_cycle[500001];
int n,m;
int cycle_ref;
void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void reset_visit(void){
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
}
void dfs(int u,int prev){
    if(visited[u]){
        cycle_ref = u;
        return;
    }
    visited[u]=true;
    for(auto v:adj[u]){
        if(v==prev) continue;
        dfs(v,u);
    }
}
bool find_cycle(int u,int prev){
    if(visited[u]){
        return true;
    }
    visited[u]=true;
    bool in_circle = false;
    for(auto v:adj[u]){
        if(v==prev) continue;
        if(in_circle) break;
        in_circle = find_cycle(v,u);
    }
    in_cycle[u] = in_circle;
    return in_cycle[u];
}
int count_child(int u,int prev){
    if(visited[u]) return -1;
    visited[u] = true;
    int child=0;
    for(auto v:adj[u]){
        if(v==prev||(in_cycle[v]&&in_cycle[m])) continue;
        child+=count_child(v,u)+1;
    }
    return child;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        add_edge(a,b);
    }
    dfs(m,-1); reset_visit();
    find_cycle(cycle_ref,-1); reset_visit();

    int max=0,wp=0;
    if(in_cycle[m]){
        for(int i=1;i<=n;i++){
            if(i==m||!in_cycle[i]) continue;
            int child = count_child(i,-1);
            if(max<child){
                max=child;
                wp=i;
            }
        }
        for(int v:adj[m]){
            if(in_cycle[v]) continue;
            int child = count_child(v,m);
            if(max<child){
                max=child;
                wp = v;
            }
        }
    }
    else{
        for(int v:adj[m]){
            int child = count_child(v,m);
            if(max<child){
                max=child;
                wp = v;
            }
        }
    }
    cout<<wp<<endl<<max;
    return 0;
}
