#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int n,m,k;
long long unsigned cost=0;
int parent[200001];
long long unsigned size[200001];
struct node{
    int u,v,w;
    bool operator<(const node&o)const{
        return w>o.w;
    }
};
priority_queue<node> q;
int find_set(int v){
    if(parent[v]==v)
        return v;
    return find_set(parent[v]);
}
void union_set(int u,int v){
    int a = find_set(u);
    int b = find_set(v);

}
int main(){
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        q.push({a,b,c});
    }
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    while(!q.empty()&&n-k-1){
        a = find_set(q.top().u);
        b = find_set(q.top().v);
        c = q.top().w;
        q.pop();
        if(a==b)
            continue;
        if(size[a]>size[b]){
            parent[b]=a;
            size[a]+=size[b];
        }
        else{
            parent[a]=b;
            size[b]+=size[a];
        }
        cost+=c;
        n--;
    }
    cout<<cost;
}
