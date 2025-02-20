#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
char name[]={'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
struct graph{
    int u,v,w;
    operator<(const graph&e)const{
        return w>=e.w;
    }
};
priority_queue<graph> edge;
void add_edge(int u,int v,int w){
    edge.push({u,v,w});
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
//set
int parent[sizeof(name)/sizeof(name[0])]={};
int set_size[sizeof(name)/sizeof(name[0])]={};
void make_set(int u){
    parent[u]=u;
    set_size[u]=1;
}
int find_set(int u){
    if(parent[u]==u)
        return u;
    find_set(parent[u]);
}
void union_set(int u,int v){
    u = find_set(u);
    v = find_set(v);
    if(set_size[u]>set_size[v])
        parent[v]=u;
    else
        parent[u]=v;
}
int kruskal(void){
    for(int i=0;i<n;i++)
        make_set(i);
    int cost=0;
    while(!edge.empty()){
        int a = edge.top().u;
        int b = edge.top().v;
        int c = edge.top().w;
        edge.pop();
        a = find_set(a);
        b = find_set(b);
        if(a==b)
            continue;
        if(set_size[a]>set_size[b]){
            parent[b]=a;
            set_size[a]+=set_size[b];
        }
        else{
            parent[a]=b;
            set_size[b]+=set_size[a];
        }
        cost+=c;
    }
    return cost;
}
int main(){
    input_edge();
    cout<<"cost : "<<kruskal();
}
