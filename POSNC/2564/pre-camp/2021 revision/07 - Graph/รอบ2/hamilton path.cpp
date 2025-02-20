#include <iostream>
#include <vector>
#include <stack>

using namespace std;
char name[] = {'S','A','B','C','D','E','F'};
int n = sizeof(name)/sizeof(name[0]);
vector<vector<int>> adj;
void add_edge(int u,int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);     //undirected graph
}
void input_edge(void){
    adj.resize(n);
    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,3);
    add_edge(1,3);
    add_edge(2,1);
    add_edge(2,4);
    add_edge(3,2);
    add_edge(4,5);
    add_edge(4,6);
    add_edge(5,6);
}
vector<int> path;
vector<bool> visited(n,false);
void dfs(int u,int level){
    if(level==n-1){
        for(auto v:path){
            cout<<name[v]<<" -> ";
        }
        return;
    }
    for(auto v:adj[u]){
        if(visited[v])
            continue;
        visited[v]=true;
        path.push_back(v);
        dfs(v,level+1);
        path.pop_back();
        visited[v]=false;
    }
}
int main(){
    input_edge();
    path.push_back(0);
    dfs(0,0);
}
