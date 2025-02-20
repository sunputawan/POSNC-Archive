#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <stack>
#define n 9

using namespace std;
char name[]={'S','A','B','C','D','E','F','G','H'};
bool visited[n];
vector<vector<pair<int,int>>> v(n);
void add_edge(void){
    v[0].push_back({1,3});
    v[0].push_back({2,2});
    v[0].push_back({3,5});
    v[1].push_back({3,3});
    v[1].push_back({7,2});
    v[2].push_back({1,4});
    v[2].push_back({4,6});
    v[3].push_back({2,4});
    v[3].push_back({8,3});
    v[4].push_back({5,2});
    v[4].push_back({6,3});
    v[5].push_back({6,5});
    v[7].push_back({4,4});
    v[7].push_back({5,5});
    v[8].push_back({1,4});
    v[8].push_back({4,4});
}
void show_edge(void){
    for(int i=0;i<n;i++){
        if(v[i].size()==0)
            continue;
        cout<<name[i]<<"-> ";
        for(int j=0;j<v[i].size();j++){
            cout<<name[v[i][j].first]<<"("<<v[i][j].second<<"), ";
        }
        cout<<endl;
    }
}
void initialize(void){
    for(int i=0;i<9;i++){
        visited[i]=false;
    }
}
void bfs(void){
    initialize();
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int s=q.front();
        cout<<name[s]<<", ";
        q.pop();
        for(auto i=v[s].begin();i!=v[s].end();i++){
            if(!visited[i->first]){
                visited[i->first]=true;
                q.push(i->first);
            }
        }
    }
    cout<<endl;
}
void dfs(void){
    initialize();
    stack<int> st;
    st.push(0);
    visited[0]=true;
    while(!st.empty()){
        int s=st.top();
        cout<<name[s]<<", ";
        st.pop();
        for(auto i=v[s].rbegin();i!=v[s].rend();i++){
            if(!visited[i->first]){
                visited[i->first]=true;
                st.push(i->first);
            }
        }
    }
    cout<<endl;
}
int main(){
    add_edge();
    show_edge();
    bfs();
    dfs();
}
