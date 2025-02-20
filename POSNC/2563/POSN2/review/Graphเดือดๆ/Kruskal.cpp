#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#define n 9

using namespace std;
unordered_map<int,int> parent;
vector<pair<pair<int,int>,int>> edges;
char name[]={'a','b','c','d','e','f','g','h','i'};
int cost=0;
void make_set(int x){
    parent[x]=x;
}
int find_set(int x){
    if(parent[x]==x)
        return parent[x];
    else
        find_set(parent[x]);
}
void union_set(int x,int y){
    parent[find_set(y)]=find_set(x);
}
void add_edge(int x,int y,int z){
    edges.push_back({{x,y},z});
}
void input_edge(void){
    add_edge(0,1,4);
    add_edge(0,7,8);
    add_edge(1,2,8);
    add_edge(1,7,11);
    add_edge(2,3,7);
    add_edge(2,5,4);
    add_edge(2,8,2);
    add_edge(3,4,9);
    add_edge(3,5,14);
    add_edge(4,5,10);
    add_edge(5,6,2);
    add_edge(6,7,1);
    add_edge(6,8,6);
    add_edge(7,8,7);
}
bool ascending(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
    return a.second<=b.second;
}
void kruskal(void){
    for(int i=0;i<n;i++)
        make_set(i);
    std::sort(edges.begin(),edges.end(),ascending);
    for(int i=0;i<edges.size();i++){
        if(find_set(edges[i].first.first)!=find_set(edges[i].first.second)){
            cout<<name[edges[i].first.first]<<"<->"<<name[edges[i].first.second]<<" (cost"<<edges[i].second<<")"<<endl;
            cost+=edges[i].second;
            union_set(edges[i].first.first,edges[i].first.second);
        }
    }
}
int main(){
    input_edge();
    kruskal();
    cout<<endl<<"Total cost :"<<cost<<endl;
}
