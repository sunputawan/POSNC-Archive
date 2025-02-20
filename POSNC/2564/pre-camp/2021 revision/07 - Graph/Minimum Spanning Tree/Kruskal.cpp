#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define n 9

using namespace std;
struct edge{
    int u,v,w;
};

vector<edge> g;
void add_edge(int u,int v,int w){
    g.push_back({u,v,w});
}
bool by_weight(const edge &a,const edge &b){
    return a.w<=b.w;
}
void input_edge(void){
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
unordered_map<int,int> parent;
void make_set(int v){
    parent[v] = v;
}
int find_set(int v){
    if(parent[v]==v)
        return v;
    find_set(parent[v]);
}
void union_set(int u,int v){
    parent[find_set(v)] = find_set(u);
}

int kruskal(void){
    int cost=0;
    for(auto e:g){
        if(find_set(e.u)!=find_set(e.v)){
            union_set(e.u,e.v);
            cost+=e.w;
        }
    }
    return cost;
}
int main(){
    input_edge();
    std::sort(g.begin(),g.end(),by_weight);
    for(int i=0;i<n;i++)
        make_set(i);
    for(int i=0;i<g.size();i++)
        cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
    cout<<"Minimum cost : "<<kruskal()<<endl;
}
