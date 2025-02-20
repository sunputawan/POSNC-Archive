#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

using namespace std;
char name[]={'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
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
void print_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(auto v:adj[i])
            cout<<name[v.first]<<"("<<v.second<<"), ";
        cout<<endl;
    }
}
void BFS(void){
    queue<int> q;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int u = q.front();
        cout<<name[u]<<"->";
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v.first]){
                q.push(v.first);
                visited[v.first] = true;
            }
        }
    }
    cout<<endl;
}
void DFS(void){
    stack<int> q;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int u = q.top();
        cout<<name[u]<<"->";
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v.first]){
                q.push(v.first);
                visited[v.first] = true;
            }
        }
    }
    cout<<endl;
}
int main(){
    input_edge();
    print_graph();
    cout<<"Breadth First Search : ";
    BFS();
    cout<<"Depth First Search : ";
    DFS();
}
