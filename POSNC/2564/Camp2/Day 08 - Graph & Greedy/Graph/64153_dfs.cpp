#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#define INTMAX 999999

using namespace std;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
int src = 0;
vector<vector<pair<int,int>>> adj;
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

void dfs(void){
    stack<int> s;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    s.push(src);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(visited[u]) continue;
        visited[u] = true;
        cout<<name[u]<<" -> ";
        for(auto v:adj[u]){
            s.push(v.first);
        }
    }
}
int main(){
    input_edge();
    show_graph();
    dfs();
}
