#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>> adj;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n=sizeof(name)/sizeof(name[0]);
void input_edge(void){
    adj.resize(n);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(3);
    adj[1].push_back(7);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(8);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[4].push_back(8);
    adj[5].push_back(6);
    adj[7].push_back(4);
    adj[7].push_back(5);
    adj[8].push_back(1);
    //adj[8].push_back(4);
}
vector<bool> visited(n,false);
vector<int> parent(n);
vector<bool> available(n,true);
void show_edge(void){
    cout<<"My Graph :\n";
    for(int i=0;i<n;i++){
        cout<<" "<<name[i]<<" -> ";
        for(auto v:adj[i]){
            cout<<name[v]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print_cycle(int start,int end){
    stack<int> cyc;
    cyc.push(start);
    int u=end;
    while(u!=start){
        cyc.push(u);
        u=parent[u];
    }
    cout<<"Cycle Detected : ";
    cout<<name[start];
    while(!cyc.empty()){
        cout<<" -> "<<name[cyc.top()];
        cyc.pop();
    }
    cout<<endl;
}
void dfs(int u,int root){
    if(!available[u]){
        int tmp=u;
        //available[u]=true;
        return;
    }
    if(visited[u]){
        print_cycle(u,parent[u]);
        return;
    }
    visited[u]=true;
    for(auto v:adj[u]){
        parent[v]=u;
        dfs(v,root);
    }
    visited[u]=false;
    available[u]=false;
}
void cycle_detection(void){
    for(int i=0;i<n;i++){
        cout<<"New round!\n";
        dfs(i,i);
    }
}
int main(){
    input_edge();
    show_edge();
    cycle_detection();
}
