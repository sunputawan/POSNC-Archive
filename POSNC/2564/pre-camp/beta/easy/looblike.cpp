#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;
struct node{
    int data;
    int copy;
};
vector<node> q;
typedef struct node* NP;
NP make_node(int x){
    NP new_node=NP(malloc(sizeof(node)));
    new_node->data=x;
    new_node->copy=0;
    return new_node;
}
void add_node(int x){
    NP new_node=make_node(x);
    q.push_back(*new_node);
}
void initialize(void){
    q.push_back(*make_node(v[0]));
    v.erase(v.begin());
}
int main(){
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    std::sort(v.begin(),v.end());
    int pre=v[0],this_copy=0,max_copy=0;
    initialize();
    while(!v.empty()){
        if(v[0]==pre){
            q[q.size()-1].copy++;
            this_copy++;
            v.erase(v.begin());
        }
        else{
            if(max_copy<this_copy)
                max_copy=this_copy;
            this_copy=0;
            q.push_back(*make_node(v[0]));
            pre=v[0];
            v.erase(v.begin());
        }
        if(max_copy<this_copy)
                max_copy=this_copy;
    }
    for(int i=0;i<q.size();i++){
        if(q[i].copy!=max_copy)
            continue;
        cout<<q[i].data<<" ";
    }
}
