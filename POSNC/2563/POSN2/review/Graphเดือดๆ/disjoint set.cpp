#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<int,int> parent;
int a[]={14,4,9,5,4,9,14,5};
void make_set(int x){
    parent[x]=x;
}
int find(int x){
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}
void union_set(int x,int y){
    parent[find(y)]=find(x);
}
void show_parent(void){
    for(auto i:a){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
}
int main(){
    for(auto i:a){
        make_set(i);
    }
    show_parent();
    union_set(9,5);
    cout<<"union 9 and 5 : ";
    show_parent();
    union_set(14,4);
    cout<<"union 14 and 4 : ";
    show_parent();
    union_set(14,9);
    cout<<"union 4 and 5 : ";
    show_parent();
}

