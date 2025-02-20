#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <set>
#define n 9
#define inf 999999

using namespace std;
char name[]={'S','A','B','C','D','E','F','G','H'};
struct stats{
    int d;
    int pre;
    stats(){
        d=inf;
        pre=-1;
    }
}node[n];
struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second<b.second;
    }
};
vector<vector<pair<int,int>>> adj(n);
set<pair<int,int>,cmp> s; //set<node,node.d>
void add_edge(void){
    adj[0].push_back(make_pair(1,3)); //S,A,B,C,D,E,F,G,H = 0,1,2,3,4,5,6,7,8 respectively
    adj[0].push_back(make_pair(2,2)); // pair<node,weight>
    adj[0].push_back(make_pair(3,5));
    adj[1].push_back(make_pair(3,3));
    adj[1].push_back(make_pair(7,2));
    adj[2].push_back(make_pair(1,5));
    adj[2].push_back(make_pair(4,6));
    adj[3].push_back(make_pair(2,4));
    adj[3].push_back(make_pair(8,3));
    adj[4].push_back(make_pair(5,2));
    adj[4].push_back(make_pair(6,3));
    adj[5].push_back(make_pair(6,5));
    adj[7].push_back(make_pair(4,4));
    adj[7].push_back(make_pair(5,5));
    adj[8].push_back(make_pair(1,4));
    adj[8].push_back(make_pair(4,4));
}
void relax(int u,int v,int w){
    if(node[v].d>node[u].d+w){
        s.erase({v,node[v].d});
        node[v].d=node[u].d+w;
        node[v].pre=u;
        s.insert({v,node[v].d});
    }
    return;
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
        int u=s.begin()->first;
        cout<<"\t";
        for(auto i=s.begin();i!=s.end();i++)
            cout<<name[i->first]<<":"<<i->second<<"  ";
        cout<<endl;
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
