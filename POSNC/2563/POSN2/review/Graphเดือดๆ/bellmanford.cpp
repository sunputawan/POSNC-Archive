#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define n 9
#define inf 99999

using namespace std;
struct stats{
    int d;
    int pre;
}st[n];
char name[]={'S','A','B','C','D','E','F','G','H'};
vector<vector<pair<int,int>>> adj(n);
void add_edge(void){
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
void initialize(void){
    for(int i=0;i<9;i++){
        st[i].d=inf;
        st[i].pre=-1;
    }
    st[0].d=0;
    st[0].pre=-1;
}
void relax(int u,int v,int w){
    if(st[v].d>st[u].d+w){
        st[v].d=st[u].d+w;
        st[v].pre=u;
    }
}
void bellmanford(void){
    initialize();
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            relax(i,adj[i][j].first,adj[i][j].second);
        }
    }
}
void show_shortest_path(void){
    stack<int> s;
    for(int i=1;i<n;i++){
        cout<<"shortest path from "<<name[0]<<" to "<<name[i]<<" takes cost : "<<st[i].d;
        int p=i;
        while(st[p].pre!=-1){
            s.push(p);
            p=st[p].pre;
        }
        cout<<" ("<<name[0];
        while(!s.empty()){
            int a=s.top();
            s.pop();
            cout<<"->"<<name[a];
        }
        cout<<")\n";
    }
    return;
}
int main(){
    add_edge();
    bellmanford();
    show_shortest_path();
}
