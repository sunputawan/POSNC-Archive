#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#define INTMAX 999999

using namespace std;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
int src = 0;
vector<vector<pair<int,int>>> adj;
struct stats{
    int d;
    int pre;
    stats(){
        d=INTMAX;
        pre=-1;
    }
}node[sizeof(name)/sizeof(name[0])];
void add_edge(int u,int v,int e){
    adj[u].push_back({v,e});
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
struct sec_ref{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<=b.second;
    }
};
void dijsktra(void){
    set<pair<int,int>,sec_ref> s;
    node[src].d=0;
    s.insert({src,0});
    while(!s.empty()){
        int u = s.begin()->first;
        for(auto k:s)
            cout<<name[k.first]<<":"<<k.second<<" ";
        cout<<endl;
        s.erase(s.begin());
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            if(node[v].d>node[u].d+adj[u][i].second){
                node[v].d = node[u].d+adj[u][i].second;
                node[v].pre  = u;
                s.insert({v,node[v].pre});
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
    show_graph();
    dijsktra();
    print_shortest_path();
}
