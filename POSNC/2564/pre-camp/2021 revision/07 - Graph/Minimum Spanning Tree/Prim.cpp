#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <algorithm>
#define INTMAX 99999


using namespace std;
vector<vector<pair<int,int>>> adj;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
struct stats{
    int d;
    int pre;
    stats(){
        d = INTMAX;
        pre = -1;
    }
};
vector<stats> node(n);
void add_edge(int u,int v,int e){
    adj[u].push_back({v,e});
    adj[v].push_back({u,e});
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
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<=b.second;
    }
};
void prim(void){
    set<pair<int,int>,cmp> s;
    bool in_MST[n];
    for(int i=0;i<n;i++)
        in_MST[i]=false;
    node[0].d = 0;
    s.insert({0,0});
    while(!s.empty()){
        int u = s.begin()->first;
        cout<<"Operating : "<<name[u]<<" (from "<<name[node[u].pre]<<")"<<endl;
        for(auto k:s ){
            cout<<name[k.first]<<":"<<k.second<<" ";
        }
        cout<<endl;
        s.erase(s.begin());
        if(in_MST[u])
            continue;
        in_MST[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            if(!in_MST[v]&&node[v].d > adj[u][i].second){
                node[v].d = adj[u][i].second;
                node[v].pre = u;
                s.insert({v,node[v].d});
                for(auto k:s ){
                    cout<<name[k.first]<<":"<<k.second<<" ";
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
}
void show_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++)
            cout<<name[adj[i][j].first]<<"("<<adj[i][j].second<<") , ";
        cout<<endl;
    }
}
void minimum_cost(void){

}
int main(){
    input_edge();
    show_graph();
    prim();
    cout<<"Minimum Spanning Tree\n";
    int cost=0;
    for(int i=0;i<n;i++){
        cout<<name[i]<<" : "<<node[i].d<<" (from "<<name[node[i].pre]<<")\n";
        cost+=node[i].d;
    }
    cout<<"\n cost : "<<cost<<endl;
}
