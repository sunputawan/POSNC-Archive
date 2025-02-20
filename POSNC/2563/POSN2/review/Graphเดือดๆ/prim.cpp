#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#define n 9
#define inf 9999999

using namespace std;
vector<vector<pair<int,int>>> edges(n);
struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second<=b.second;
    }
};
set<pair<int,int>,cmp> s;
char name[]={'a','b','c','d','e','f','g','h','i'};
int cost=0;
void add_edge(int x,int y,int z){
    edges[y].push_back({x,z});
    edges[x].push_back({y,z});
}
struct stats{
    int key;
    int pre;
    bool available;
    stats(){
        key=inf;
        pre=-1;
        available=true;
    }
}node[n];
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
void initialize(void){
    for(int i=0;i<n;i++){
        s.insert({i,node[i].key});
    }
}
void prim(void){
    node[0].key=0;
    initialize();
    while(!s.empty()){
        int u=s.begin()->first;
        s.erase(s.begin());
        node[u].available=false;
        for(auto i:edges[u]){
            if(node[i.first].available&&i.second<node[i.first].key){
                int v=i.first;
                auto it=std::find_if(s.begin(),s.end(), [&v](const pair<int,int> &a){return a.first==v;});
                s.erase(it);
                node[v].pre=u;
                node[v].key=i.second;
                s.insert({v,node[v].key});
            }
        }
    }
}
int main(){
    input_edge();
    prim();
    for(int i=0;i<n;i++){
        cout<<node[i].key<<endl;
        cost+=node[i].key;
    }
    cout<<endl<<"Total cost :"<<cost<<endl;
}
