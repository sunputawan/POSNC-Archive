#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;
unordered_map<int,int> parent;
int n = 20;
void make_set(int v){
    parent[v] = v;
}
int find_set(int v){
    if(parent[v]==v)
        return v;
    find_set(parent[v]);
}
void union_set(int u,int v){
    parent[find_set(u)] = find_set(v);
}
void print_set(int v){
    stack<int> s;
    cout<<"Your set (as "<<v<<" ref) : ";
    while(v!=parent[v]){
        cout<<v<<",";
        s.push(v);
        v=parent[v];
    }
    cout<<v<<endl;
}
void show_parent(void){
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
}
int main(){
    for(int i=0;i<n;i++){
        make_set(i);
        print_set(i);
    }
    show_parent();
    union_set(0,1);
    union_set(1,2);
    union_set(0,3);
    union_set(2,4);
    show_parent();
    print_set(0);
    print_set(1);
}
