#include <iostream>
#include <vector>

using namespace std;

struct edge{
    int s,v,w;
}path[100000];
struct node{
    int key;
    int to[3];
    int dis[3];
}vertex[50000];

int main(){
    int E,V,a,b,c;
    cin>>E>>V;
    for(int i=0;i<V;i++){
        cin>>a>>b>>c;
        path[i].s=a;
        path[i].v=b;
        path[i].w=c;
    }
}
