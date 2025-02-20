#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#define INTMAX 999999

using namespace std;
char name[]={'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
vector<vector<pair<int,int>>> adj;
void add_edge(int u,int v,int w){
    adj[u].push_back({v,w});
}
struct stats{
    int d;
    int pre;
    stats(){
        d=INTMAX;
        pre=-1;
    }
}node[sizeof(name)/sizeof(name[0])];
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
void print_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(auto v:adj[i])
            cout<<name[v.first]<<"("<<v.second<<"), ";
        cout<<endl;
    }
}
int src=0;

void bellmanford(void){
    node[0].d = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            if(node[adj[i][j].first].d>node[i].d+adj[i][j].second){
                node[adj[i][j].first].d = node[i].d+adj[i][j].second;
                node[adj[i][j].first].pre = i;
            }
        }
    }
}
void print_shortest_path(void){
    cout<<"\nStats :\n";
    for(int i=0;i<n;i++)
        cout<<name[i]<<":"<<node[i].d<<" (from "<<name[node[i].pre]<<")\n";
    cout<<endl<<"Shortest Path : "<<endl;
    for(int i=0;i<n;i++){
        stack<int> s;
        if(i==src)
            continue;
        int v=i;
        while(v!=src){
            if(v==-1)
                break;
            s.push(v);
            v=node[v].pre;
        }
        cout<<name[i]<<" : ";
        if(v==-1){
            cout<<"Path doesn't exist!\n";
            continue;
        }
        cout<<name[src];
        while(!s.empty()){
            v=s.top();
            s.pop();
            cout<<" --"<<node[v].d-node[node[v].pre].d<<"--> "<<name[v];
        }
        cout<<" = "<<node[v].d<<endl;
    }
}
int main(){
    input_edge();
    print_graph();
    bellmanford();
    print_shortest_path();
}
