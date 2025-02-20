#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <set>
#define n 5
#define inf 999999

using namespace std;
char name[]={'s','t','x','y','z'};
vector<vector<pair<int,int>>> adj(n);
struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second<=b.second;
    }
};
set<pair<int,int>,cmp> s;
struct stats{
    int d;
    int pre;
    stats(){
        d=inf;
        pre=-1;
    }
}node[n];
void add_edge(){
    adj[0].push_back(make_pair(1,10));
    adj[0].push_back(make_pair(3,5));
    adj[1].push_back(make_pair(2,1));
    adj[1].push_back(make_pair(3,2));
    adj[2].push_back(make_pair(4,4));
    adj[3].push_back(make_pair(1,3));
    adj[3].push_back(make_pair(2,9));
    adj[3].push_back(make_pair(4,2));
    adj[4].push_back(make_pair(0,7));
    adj[4].push_back(make_pair(2,6));
}
void relax(int u,int v,int w){
    if(node[v].d>node[u].d+w){
        auto it = std::find_if(s.begin(),s.end(), [&v](const pair<int,int> &p){return p.first == v; });
        cout<<it->first<<" "<<it->second<<endl;
        s.erase(it);
        node[v].d=node[u].d+w;
        node[v].pre=u;
        s.insert({v,node[v].d});

    }
}
void initialize(void){
    node[0].d=0;
    for(int i=0;i<n;i++){
        s.insert({i,node[i].d});
    }
}
void dijsktra(void){
    initialize();
    while(!s.empty()){
        for(auto i=s.begin();i!=s.end();++i){
            cout<<name[i->first]<<":"<<i->second<<" ";
        }
        cout<<endl;
        int u=s.begin()->first;
        s.erase(s.begin());
        for(int i=0;i<adj[u].size();i++){
            relax(u,adj[u][i].first,adj[u][i].second);
        }
    }
}
void show_shortest_path(void){
    stack<int> s;
    for(int i=1;i<n;i++){
        cout<<"shortest path from "<<name[0]<<" to "<<name[i]<<" takes cost : "<<node[i].d;
        int p=i;
        while(node[p].pre!=-1){
            s.push(p);
            p=node[p].pre;
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
    dijsktra();
    show_shortest_path();
}
