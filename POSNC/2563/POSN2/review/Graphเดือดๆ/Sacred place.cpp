#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#define inf -1

using namespace std;
vector<vector<pair<int,int>>> adj(200000);
void add_edge(int x,int y,int z){
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
}
struct stats{
    int key;
    bool available;
    stats(){
        key=inf;
        available=true;
    }
}node[200000];
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>=b.second;
    }
};
set<pair<int,int>,cmp> q;
void initialize(int n){
    for(int i=0;i<n;i++){
        q.insert({i,node[i].key});
    }
}
void prim(int n){
    node[0].key=0;
    initialize(n);
    while(!q.empty()){
        int u=q.begin()->first;
        q.erase(q.begin());
        node[u].available=false;
        for(auto i:adj[u]){
            if(node[i.first].available&&i.second>node[i.first].key){
                int v=i.first;
                auto it=std::find_if(q.begin(),q.end(), [&v](const pair<int,int> &a){return a.first==v;});
                q.erase(it);
                node[v].key=i.second;
                q.insert({v,node[v].key});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add_edge(a-1,b-1,c);
    }
    prim(n);
    int cost=0;
    for(int i=1;i<n;i++){
        cost+=node[i].key-1;
    }
    cout<<cost;
}
