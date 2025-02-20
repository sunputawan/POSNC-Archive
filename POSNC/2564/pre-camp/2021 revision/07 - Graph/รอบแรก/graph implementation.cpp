#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>

using namespace std;
char name[] = {'S','A','B','C','D','E','F','G','H'};
int n = sizeof(name)/sizeof(name[0]);
vector<vector<pair<int,int>>> adj(n);
struct sec_ascending{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<b.second;
    }
};
void input_edge(void){
    adj[0].push_back({1,3});
    adj[0].push_back({2,2});
    adj[0].push_back({3,5});
    adj[1].push_back({3,3});
    adj[1].push_back({7,2});
    adj[2].push_back({1,4});
    adj[2].push_back({4,6});
    adj[3].push_back({2,4});
    adj[3].push_back({8,3});
    adj[4].push_back({5,2});
    adj[4].push_back({6,3});
    adj[5].push_back({6,5});
    adj[7].push_back({4,4});
    adj[7].push_back({5,5});
    adj[8].push_back({1,4});
    adj[8].push_back({4,4});
}
void breadth_first_search(void){
    cout<<"Breadth First Search : ";
    queue<int> q;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<name[u]<<" -> ";
        for(auto v:adj[u]){
            if(!visited[v.first]){
                q.push(v.first);
                visited[v.first]=true;
            }
        }
    }
    cout<<endl;
}
void uniform_cost_search(void){
    cout<<"Uniform Cost Search : ";
    set<pair<int,int>,sec_ascending> s;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    visited[0]=true;
    s.insert({0,0});
    while(!s.empty()){
        pair<int,int> tmp = *s.begin();
        s.erase(s.begin());
        int u = tmp.first;
        cout<<name[u]<<"("<<tmp.second<<") -> ";
        for(auto v:adj[u]){
            if(!visited[v.first]){
                s.insert({v.first,v.second});
                visited[v.first]=true;
            }
        }
    }
    cout<<endl;
}
void depth_first_search(void){
    cout<<"Depth First Search : ";
    stack<int> s;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    s.push(0);
    visited[0]=true;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        cout<<name[u]<<" -> ";
        for(auto v:adj[u]){
            if(!visited[v.first]){
                s.push(v.first);
                visited[v.first]=true;
            }
        }
    }
    cout<<endl;
}
void show_edge(void){
    cout<<"My Graph :\n";
    for(int i=0;i<adj.size();i++){
        cout<<" "<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<name[adj[i][j].first]<<"("<<adj[i][j].second<<"), ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    input_edge();
    show_edge();
    breadth_first_search();
    uniform_cost_search();
    depth_first_search();
}
