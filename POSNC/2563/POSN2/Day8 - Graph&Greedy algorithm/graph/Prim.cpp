#include <iostream>
#include <algorithm>
#include <vector>
#define V 9
#define inf 999999


using namespace std;
char map[]={'S','A','B','C','D','E','F','G','H'};
struct node{
    int key;
    int pre;
    int active;
}vertex[V];
typedef struct node* VP;
int edge[][V]={0,3,2,5,0,0,0,0,0,
               0,0,0,3,0,0,0,2,0,
               0,5,0,0,6,0,0,0,0,
               0,0,4,0,0,0,0,0,3,
               0,0,0,0,0,2,3,0,0,
               0,0,0,0,0,0,5,0,0,
               0,0,0,0,0,0,0,0,0,
               0,0,0,0,4,5,0,0,0,
               0,4,0,0,4,0,0,0,0};
bool empty(void){
    for(int i=0;i<V;i++){
        if(vertex[i].active==1)
            return false;
    }
    return true;
}
int find_min(void){
    int min=inf;
    int a;
    for(int i=0;i<V;i++){
        if(vertex[i].key<min&&vertex[i].active==1){
            min=vertex[i].key;
            a=i;
        }
    }
    return a;
}
void prim(void){
    struct node *p=vertex;
    for(int i=0;i<V;i++){
        vertex[i].key=inf;
        vertex[i].pre=-1;
        vertex[i].active=1;
    }
    vertex[0].pre=0;
    vertex[0].key=0;
    while(!empty()){
        int a=find_min();
        vertex[a].active=0;
        for(int i=0;i<V;i++){
            if(edge[a][i]>0&&vertex[i].active==1&&edge[a][i]<vertex[i].key){
                vertex[i].pre=a;
                vertex[i].key=edge[a][i];
            }
        }
    }

}
int main(){
    prim();
    int cost=0;
    for(int i=1;i<V;i++){
        cout<<map[i]<<" : "<<vertex[i].key<<" (from "<<map[vertex[i].pre]<<" )"<<endl;
        cost+=vertex[i].key;
    }
    cout<<endl<<"Total cost :"<<cost<<endl;
}
