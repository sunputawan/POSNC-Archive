#include <iostream>
#include <vector>
#define inf 99999

using namespace std;

struct node{
    char name;
    char pre;
    int d;
};
typedef struct node *np;
vector<np>Q;
int n;
char map[5]={'s','t','x','y','z'};
int edge[5][5]={0,10,0,5,0, //s,t,x,y,z
                0,0,1,2,0,
                0,0,0,0,4,
                0,3,9,0,2,
                7,0,6,0,0};
void initialize(np p){
    for(int i=0;i<n;i++){
        (p+i)->d = inf;
        (p+i)->pre = '\0';
    }
    p->d = 0;
}
int find_min_position_of_node(vector<np> a,np p,int u){
    for(int i=0;i<n;i++)
        if(a[u]->name==(p+i)->name)
            return i;
}
int find_min_position(vector<np> a,np p){
    int min=0;
    for(int i=0;i<a.size();i++)
        if(a[i]->d<a[min]->d)
            min=i;
    return min;
}
void relax(int u,int v,np p){
    if((p+v)->d > (p+u)->d + edge[u][v]){
        (p+v)->d = (p+u)->d + edge[u][v];
        (p+v)->pre = (p+u)->name;
    }
}
void dijkstra(np p){
    initialize(p);
    for(int i=0;i<n;i++)
        Q.push_back(&p[i]);
    while(Q.size()){
        int k=find_min_position(Q,p);
        int u=find_min_position_of_node(Q,p,k);
        for(int i=0;i<n;i++){
            if(edge[u][i]){
                relax(u,i,p);
            }
        }
        Q.erase(Q.begin()+k);
    }


}
int main(){
    n=5;
    np p=(np)malloc(n*sizeof(struct node));
    for(int i=0;i<n;i++){
        (p+i)->name=map[i];
    }
    dijkstra(p);
   for(int i=1;i<n;i++){
        cout<<p[i].name<<" ->shortest path cost : "<<p[i].d<<endl<<"from : "<<p[i].pre<<endl<<endl;
    }
}
