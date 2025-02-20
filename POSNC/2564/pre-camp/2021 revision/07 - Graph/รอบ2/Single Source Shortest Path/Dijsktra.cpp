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
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>=b.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> s;  // {node,d}

int src=0;

void dijsktra(void){
    vector<bool> visited(n,false);
    node[src].d = 0;
    s.push({src,0});
    while(!s.empty()){
        int u = s.top().first;
        s.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto vpair:adj[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(node[v].d>node[u].d+w){
                node[v].d = node[u].d + w;
                node[v].pre = u;
                s.push({v,node[v].d});
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
    dijsktra();
    print_shortest_path();
}
