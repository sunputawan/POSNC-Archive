#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
int parent[2501];
int size[2501];
struct edge{
    int u,v,w;
    bool operator<(const edge &o)const{
        return w<=o.w;
    }
};
int find_set(int v){
    if(parent[v]==v)
        return v;
    find_set(parent[v]);
}
priority_queue<edge> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        q.push({a,b,c});
    }
    int src,des,num;
    cin>>src>>des>>num;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    int min=q.top().w;
    while(!q.empty()&&n){
        if(find_set(src)==find_set(des)){
            break;
        }
        int a = find_set(q.top().u);
        int b = find_set(q.top().v);
        int c = q.top().w;
        q.pop();
        if(a==b) continue;
        if(size[a]>size[b]){
            parent[b]=a;
            size[a]+=size[b];
        }
        else{
            parent[a]=b;
            size[b]+=size[a];
        }
        n--;
        if(min>c)
            min=c;
    }
    cout<<ceil(float(num)/(min-1));
}
