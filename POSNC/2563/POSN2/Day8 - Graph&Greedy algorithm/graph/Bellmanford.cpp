#include <iostream>
#define inf 99999
struct node{
    char name;
    char pre;
    int d;
};
using namespace std;
typedef struct node *np;
int n;
char map[5]={'s','t','x','y','z'};
int edge[5][5]={0,6,0,7,0, //s,t,x,y,z
                0,0,5,8,-4,
                0,-2,0,0,0,
                0,0,-3,0,9,
                2,0,7,0,0};
void initialize(np p){
    for(int i=0;i<n;i++){
        (p+i)->d = inf;
        (p+i)->pre = '\0';
    }
    p->d = 0;
}
void relax(int u,int v,np p){
    if((p+v)->d > (p+u)->d + edge[u][v]){
        (p+v)->d = (p+u)->d + edge[u][v];
        (p+v)->pre = (p+u)->name;
    }
}
void bellman_ford(np p){
    initialize(p);
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(edge[j][i])
                relax(j,i,p);
        }
    }
}
int main(){
    n=5;
    np p=(np)malloc(n*sizeof(struct node));
    for(int i=0;i<n;i++){
        (p+i)->name=map[i];
    }
    bellman_ford(p);
    for(int i=1;i<n;i++){
        cout<<p[i].name<<" ->shortest path cost : "<<p[i].d<<endl<<"from : "<<p[i].pre<<endl<<endl;
    }
}
