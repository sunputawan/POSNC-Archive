#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n=sizeof(name)/sizeof(name[0]);
void add_edge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void input_edge(void){
    adj.resize(n);
    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,3);
    add_edge(1,3);
    add_edge(1,7);
    add_edge(2,1);
    add_edge(2,4);
    add_edge(3,2);
    add_edge(3,8);
    add_edge(4,5);
    add_edge(4,6);
    add_edge(5,6);
    add_edge(7,4);
    add_edge(7,5);
    add_edge(8,1);
    add_edge(8,4);
}
void show_edge(void){
    cout<<"My Graph :\n";
    for(int i=0;i<adj.size();i++){
        cout<<" "<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<name[adj[i][j]]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool visited[sizeof(name)/sizeof(name[0])];
int color[sizeof(name)/sizeof(name[0])]={};
void coloring(){
    for(int i=0;i<n;i++){
        if(visited[i])
            continue;

        visited[i]=true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(color[u]==color[v])
                    color[v]++;
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
}
void reset_visited(void){
    for(int i=0;i<n;i++)
        visited[i]=false;
}
void bfs(void){
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int u = q.front();
        cout<<name[u]<<"("<<color[u]<<") -> ";
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}
int main(){
    input_edge();
    show_edge();
    reset_visited();
    coloring();
    reset_visited();
    bfs();
}
