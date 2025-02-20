#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define inf 9999999

using namespace std;
vector<vector<pair<int,int>>> adj(10000);
vector<int>d;
vector<int>p;
int n,m,x,y,z;
void add_edge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void dijsktra(int s){
    d[s]=0;
    set<pair<int,int>>q;
    q.insert({0,s});

    while(!q.empty()){
        cout<<endl;
        int v=q.begin()->second;
        q.erase(q.begin());
        for(auto edge:adj[v]){
            for(int i=0;i<d.size();i++){
            cout<<d[i]<<" ";
            }
            int to =edge.first,len=edge.second;
            if(d[v]+len<d[to]){
                q.erase({d[to],to});
                d[to]=d[v]+len;
                p[to]=v;
                q.insert({d[to],to});
            }
        }
    }
}

int main(){
    int a,b,c;
    cin>>n>>m;
    cin>>x>>y>>z;

    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        add_edge(a,b,c);
    }
    for(int i=0;i<n;i++){
        d.push_back(inf);
        p.push_back(-1);
    }
    dijsktra(n);
}
