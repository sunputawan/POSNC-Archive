#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <stack>
#define n 5

using namespace std;
char name[]={'A','B','C','D','E'};
bool visited[n];
vector<vector<pair<int,int>>> v(n);
stack<int> s;
void add_edge(void){
    v[0].push_back({1,0});
    v[0].push_back({2,0});
    v[0].push_back({3,0});
    v[0].push_back({4,0});
    v[1].push_back({3,0});
    v[2].push_back({3,0});
    v[2].push_back({4,0});
    v[3].push_back({4,0});
}
void initialize(void){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

}
void topological_recursive(int u){
    visited[u]=true;
    for(auto i=v[u].begin();i!=v[u].end();i++){
        if(!visited[i->first]){
            topological_recursive(i->first);
        }
    }
    s.push(u);
}
void topological_sorting(void){
    initialize();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topological_recursive(i);
        }
    }
    while(!s.empty()){
        cout<<name[s.top()]<<", ";
        s.pop();
    }
}
int main(){
    add_edge();
    topological_sorting();
}
