#include <bits/stdc++.h>

using namespace std;
struct edge{
    int u,v,w;
    bool operator<(const edge&e)const{
        return w<e.w;
    }
};

priority_queue<edge> g;
int parent[200001];
int si[200001]={};
int m,n;
int find_set(int v){
    if(parent[v]==v)
        return v;
    find_set(parent[v]);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        si[i]=1;
        parent[i]=i;
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g.push({a,b,c-1});
    }

    long long cost=0;

    while((n-1)){
        a=find_set(g.top().u);
        b=find_set(g.top().v);
        c=g.top().w;
        g.pop();
        if(a==b) continue;
        if(si[a]<si[b]){
            parent[a]=b;
            si[b]+=si[a];
        }
        else{
            parent[b]=a;
            si[a]+=si[b];
        }
        cost+=c;
        n--;
    }
    cout<<cost;
}
