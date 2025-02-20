/*
TASK: PublicHealthNetwork.cpp
LANG: C++
AUTHOR: Putawan Sratongtuan
ID: 63085
*/
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define inf 9999999
int key[9999999];
int n,m;
using namespace std;
struct stats{
    int d;
    bool available;
    stats(){
        d=inf;
        available=true;
    }
}node[9999999];
vector<vector<pair<int,int>>> adj(9999999);
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<=b.second;
    }
};
set<pair<int,int>,cmp> s;
void add_edge(int x,int y){
    adj[x].push_back({y,key[x]+key[y]});
    adj[y].push_back({x,key[x]+key[y]});
}
void initialize(void){
    node[0].d=0;
    for(int k=0;k<n;k++){
        s.insert({k,node[k].d});
    }
}
void prim(void){
    initialize();
    while(!s.empty()){
        int u=s.begin()->first;
        s.erase(s.begin());
        node[u].available=false;
        for(int i=0;i<adj[u].size();i++){
            if(node[adj[u][i].first].available&&node[adj[u][i].first].d>adj[u][i].second){
                int v=adj[u][i].first;
                auto it=std::find_if(s.begin(),s.end(), [&v](const pair<int,int> &a){return a.first==v;});
                s.erase(it);
                s.erase({v,node[v].d});
                node[v].d=adj[u][i].second;
                s.insert({v,node[v].d});
            }
        }
    }
}
int main(){

    cin>>n>>m;

    for(int k=0;k<n;k++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c-b<=0)
            key[a]=1;
        else
            key[a]=c-b;
    }
    for(int k=0;k<m;k++){
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
    }
    prim();
    int total=0;
    for(int k=0;k<n;k++){
        total+=node[k].d;
    }
    cout<<total;
}
