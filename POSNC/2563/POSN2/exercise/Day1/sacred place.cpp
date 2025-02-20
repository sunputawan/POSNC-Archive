#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int parent[200000];
struct edge{
    int s,d,l;
    bool operator < (const edge& a) const{
        return l<a.l;
    }
};
int find(int i){
    if(parent[i]==i)
        return i;
    return parent[i]=find(parent[i]);
}
int main(){
    int N,M;
    cin>>N>>M;
    int s,d,l;
    priority_queue<edge> pq;
    for(int i=0;i<M;i++){
        cin>>s>>d>>l;
        pq.push({s-1,d-1,l-1});
    }
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    ll flag=0;
    while(!pq.empty()){
        int u = pq.top().s;
        int v = pq.top().d;
        int w = pq.top().l;
        int a = find(u);
        int b = find(v);
        pq.pop();
        if(a!=b){
            parent[a]=b;
            flag+=w;
        }
    }
    cout << flag;
}
