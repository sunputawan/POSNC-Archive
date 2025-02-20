#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INTMAX 999999

using namespace std;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
int src = 0;
vector<vector<pair<int,int>>> adj;
struct stats{
    int d;
    int pre;
    stats(){
        d=INTMAX;
        pre=-1;
    }
}node[sizeof(name)/sizeof(name[0])];
void add_edge(int u,int v,int w){
    adj[u].push_back({v,w});
}
void input_edge(void){
    adj.resize(n);
    add_edge(0,1,3);
    add_edge(0,2,2);
    add_edge(0,3,5);
    add_edge(1,3,3);
    add_edge(1,7,2);
    add_edge(2,1,4);
    add_edge(2,4,6);
    add_edge(3,2,4);
    add_edge(3,8,3);
    add_edge(4,5,2);
    add_edge(4,6,3);
    add_edge(5,6,5);
    add_edge(7,4,4);
    add_edge(7,5,5);
    add_edge(8,1,4);
    add_edge(8,4,4);
}
void show_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++)
            cout<<name[adj[i][j].first]<<"("<<adj[i][j].second<<") , ";
        cout<<endl;
    }
    cout<<endl;
}

void dijsktra(void){
    priority_queue<pair<int,int>> pq;
    node[src].d=0;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto vpair:adj[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(node[v].d>node[u].d+w){
                node[v].d = node[u].d+w;
                node[v].pre = u;
                pq.push({node[v].d,v});
            }
        }
    }
}
void show_path(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" : "<<node[i].d<<" (from "<<name[node[i].pre]<<")\n";
    }
}
int main(){
    input_edge();
    show_graph();
    dijsktra();
    show_path();
}
