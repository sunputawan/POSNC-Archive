#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;
// using Depth First Search in implementation of cycle detecting.
vector<vector<pair<int,int>>> adj;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n=sizeof(name)/sizeof(name[0]);
void input_edge(void){
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
void show_edge(void){
    cout<<"My Graph :\n";
    for(int i=0;i<n;i++){
        cout<<" "<<name[i]<<" -> ";
        for(auto v:adj[i]){
            cout<<name[v.first]<<"("<<v.second<<"), ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int color[sizeof(name)/sizeof(name[0])],parent[sizeof(name)/sizeof(name[0])];
bool thereiscircle=false;
void initialize(){
    for(int i=0;i<n;i++){
        color[i]=0;
        parent[i]=-1;
    }
}
void print_cycle(int start,int end){
    stack<int> cycle;
    cycle.push(start);
    int v=end;
    while(v!=start){
        cycle.push(v);
        v=parent[v];
    }
    cycle.push(start);
    cout<<"Cycle found : ";
    cout<<name[cycle.top()];
    cycle.pop();
    while(!cycle.empty()){
        cout<<" -> "<<name[cycle.top()];
        cycle.pop();
    }
    cout<<endl;
}
void dfs(int v){
    color[v]=1;
    for(auto u:adj[v]){
        if(color[u.first]==0){
            parent[u.first]=v;
            dfs(u.first);
        }
        else if(color[u.first]==1){ //cycle detected
            thereiscircle=true;
            print_cycle(u.first,v);
        }
    }
    color[v]=2;
}
void cycle_detected(void){
    initialize();
    dfs(0);
    if(!thereiscircle){
        cout<<"There is no circle"<<endl;
        return;
    }
}
int main(){
    input_edge();
    show_edge();
    cycle_detected();
}
