#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <algorithm>
#define INTMAX 999999

using namespace std;
vector<vector<pair<int,int>>> adj;
char name[]={'s','t','x','y','z'};
int n=sizeof(name)/sizeof(name[0]);
void add_edge(int u,int v,int e){
    adj[u].push_back({v,e});
}
struct stats{
    int d;
    int pre;
    stats(){
        d=INTMAX;
        pre=-1;
    }
}node[sizeof(name)/sizeof(name[0])];
struct sec_ref{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<=b.second;
    }
};
void input_edge(void){
    adj.resize(n);
    add_edge(0,1,10);  //s
    add_edge(0,3,5);
    add_edge(1,2,1);   //t
    add_edge(1,3,2);
    add_edge(2,4,4);   //x
    add_edge(3,1,3);   //y
    add_edge(3,2,9);
    add_edge(3,4,2);
    add_edge(4,0,7);   //z
    add_edge(4,2,6);

}
void show_graph(void){
    for(int i=0;i<n;i++){
        cout<<name[i]<<" -> ";
        for(int j=0;j<adj[i].size();j++)
            cout<<name[adj[i][j].first]<<"("<<adj[i][j].second<<") , ";
        cout<<endl;
    }
}
void dijsktra(void){
    node[0].d = 0;
    set<pair<int,int>,sec_ref> s; //implement set as an priority queue
    s.insert({0,0});
    cout<<"\nOperation of priority queue :";
    while(!s.empty()){
        int u = s.begin()->first;
        s.erase(s.begin());
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            if(node[v].d>node[u].d+adj[u][i].second){
                for(auto k:s)
                    cout<<name[k.first]<<":"<<node[k.first].d<<" ";
                cout<<endl;
                node[v].d = node[u].d + adj[u][i].second;
                node[v].pre = u;
                s.insert({v,node[v].d});
            }
        }
    }
}
void print_shortest_path(void){
    cout<<endl<<"Stats\n";
    for(int i=0;i<n;i++){
        cout<<name[i]<<":"<<node[i].d<<" (from ";
        if(node[i].pre==-1)
            cout<<"NULL";
        else
            cout<<name[node[i].pre];
        cout<<")"<<endl;
    }
    cout<<endl<<endl;
    cout<<"Shortest Path :\n";
    for(int i=1;i<n;i++){
        stack<int> s;
        int v=i;
        while(v!=0){
            s.push(v);
            v=node[v].pre;
        }
        cout<<name[i]<<" : "<<name[0];
        while(!s.empty()){
            v=s.top();
            s.pop();
            cout<<" --"<<node[v].d-node[node[v].pre].d<<"--> "<<name[v];
        }
        cout<<" = "<<node[v].d<<endl;
    }
}
int main(){
    input_edge();
    show_graph();
    dijsktra();
    print_shortest_path();
}
