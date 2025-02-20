#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define INTMAX 1e9+5

using namespace std;
vector<vector<pair<int,int>>> adj;

int n,m,src,des,bud;
vector<int> dsrc(10005,INTMAX);
vector<int> ddes(10005,INTMAX);
void add_edge(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void dijkstrasrc(void){
    set<pair<int,int>> s;
    s.insert({0,src});
    dsrc[src] =  0;
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto p:adj[u]){
            int v = p.first;
            int w = p.second;
            if(bud>=dsrc[u]+w&&dsrc[v]>dsrc[u]+w){
                s.erase({dsrc[v],v});
                dsrc[v] = dsrc[u]+w;
                s.insert({dsrc[v],v});
            }
        }
    }
}
void dijkstrades(void){
    set<pair<int,int>> s;
    s.insert({0,des});
    ddes[des] =  0;
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto p:adj[u]){
            int v = p.first;
            int w = p.second;
            if(ddes[v]>ddes[u]+w){
                s.erase({ddes[v],v});
                ddes[v] = ddes[u]+w;
                s.insert({ddes[v],v});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    cin>>src>>des>>bud;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add_edge(x,y,z);
    }
    dijkstrasrc();
    if(dsrc[des]!=INTMAX){
        cout<<des<<" "<<dsrc[des]<<" 0";
        return 0;
    }
    dijkstrades();

    int minfromdes = INTMAX;
    int minfromdesidx = -1;
    for(int i=0;i<n;i++){
        if(dsrc[i]!=INTMAX&&minfromdes>ddes[i]){
            minfromdes = ddes[i];
            minfromdesidx = i;
        }
    }

    cout<<minfromdesidx<<" "<<dsrc[minfromdesidx]<<" "<<ddes[minfromdesidx];
}
