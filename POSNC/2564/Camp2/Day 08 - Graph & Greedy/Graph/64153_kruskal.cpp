#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INTMAX 999999

using namespace std;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
struct graph{
    int u,v,w;
    bool operator<(const graph &g)const{
        return w>=g.w;
    }
};
priority_queue<graph> pq;
void add_edge(int u,int v,int w){
    pq.push({u,v,w});
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
void show_graph(priority_queue<graph> pq){
    while(!pq.empty()){
        cout<<name[pq.top().u]<<" <-> "<<name[pq.top().v]<<" ("<<pq.top().w<<")\n";
        pq.pop();
    }
}
void initialize(int *parent,int *size){
    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
}
int find_set(int v,int parent[]){
    if(parent[v]==v)
        return v;
    return find_set(parent[v],parent);
}
vector<graph> track;
int kruskal(void){
    int parent[n];
    int size[n];
    initialize(parent,size);
    int i=0;
    int cost = 0;
    while(!pq.empty()&&i!=n){
        int a = pq.top().u;
        int b = pq.top().v;
        int c = pq.top().w;
        pq.pop();
        int atmp = a;
        int btmp = b;
        a = find_set(a,parent);
        b = find_set(b,parent);
        if(a==b) continue;
        track.push_back({atmp,btmp,c});
        cost+=c;
        if(size[a]>size[b]){
            parent[b] = a;
            size[a]+=size[b];
        }
        else{
            parent[a] = b;
            size[b]+=size[a];
        }
        i++;
    }
    return cost;
}
void showMinimumSpanningTree(void){
    cout<<"Selected Edge : \n";
    for(auto edge:track){
        cout<<"\t"<<name[edge.u]<<" <-> "<<name[edge.v]<<" ("<<edge.w<<")\n";
    }
}
int main(){
    input_edge();
    show_graph(pq);
    cout<<"\nMinimum Cost : "<<kruskal()<<'\n';
    showMinimumSpanningTree();
}
