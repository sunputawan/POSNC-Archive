#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#define INTMAX 999999

using namespace std;
vector<vector<pair<int,int>>> adj;
char name[]={'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
struct stats{
    int d;
    int pre;
    stats(){
        d=INTMAX;
        pre=-1;
    }
}node[sizeof(name)/sizeof(name[0])];
void add_edge(void){
    adj.resize(n);
    adj[0].push_back({1,3});
    adj[0].push_back({2,2});
    adj[0].push_back({3,5});
    adj[1].push_back({3,3});
    adj[1].push_back({7,2});
    adj[2].push_back({1,4});
    adj[2].push_back({4,6});
    adj[3].push_back({2,4});
    adj[3].push_back({8,3});
    adj[4].push_back({5,2});
    adj[4].push_back({6,3});
    adj[5].push_back({6,5});
    adj[7].push_back({4,4});
    adj[7].push_back({5,5});
    adj[8].push_back({1,4});
    adj[8].push_back({4,4});
}
void show_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++)
            cout<<name[adj[i][j].first]<<"("<<adj[i][j].second<<"), ";
        cout<<endl;
    }
}
void relax(int u,int v,int w){
    if(node[v].d>node[u].d+w){
        node[v].d = node[u].d+w;
        node[v].pre = u;
    }
}
void bellmanford(void){
    node[0].d = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            relax(i,adj[i][j].first,adj[i][j].second);
        }
    }
}
void show_shortest_path(void){
    cout<<"\nStats :\n";
    for(int i=0;i<n;i++)
        cout<<name[i]<<":"<<node[i].d<<" (from "<<name[node[i].pre]<<")\n";
    cout<<endl<<"Shortest Path : "<<endl;
    for(int i=0;i<n;i++){
        stack<int> s;
        if(i==0)
            continue;
        int v=i;
        while(v!=0){
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
        cout<<name[0];
        while(!s.empty()){
            v=s.top();
            s.pop();
            cout<<" --"<<node[v].d-node[node[v].pre].d<<"--> "<<name[v];
        }
        cout<<" = "<<node[v].d<<endl;
    }
}
int main(){
    add_edge();
    show_graph();
    bellmanford();
    show_shortest_path();
}
