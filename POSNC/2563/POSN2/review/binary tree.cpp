#include <iostream>

using namespace std;
struct node{
    int data;
    int copy;
    node* left;
    node* right;
};
typedef struct node* NP;
NP make_node(int x){
    NP new_node=(NP)malloc(sizeof(node));
    new_node->data=x;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->copy=1;
    return new_node;
}
void set_left(NP parent,NP child){
    parent->left=child;
}
void set_right(NP parent,NP child){
    parent->right=child;
}
void add_node(NP* root_ref,int x){
    NP new_node=make_node(x);
    if(*root_ref==NULL){
        *root_ref=new_node;
        return;
    }
    NP p=*root_ref;
    while(p->data!=x&&((x<p->data&&p->left!=NULL)||(x>p->data&&p->right!=NULL))){
        if(x<p->data&&p->left!=NULL){
            p=p->left;
        }
        else if(x>p->data&&p->right!=NULL){
            p=p->right;
        }
        else if(x==p->data)
            break;
    }
    if(p->data==x)
        p->copy++;
    if(x>p->data)
        set_right(p,new_node);
    if(x<p->data)
        set_left(p,new_node);
}
void ascending(NP tp){
    if(tp!=NULL){
        ascending(tp->left);
        cout<<tp->data<<"("<<tp->copy<<"), ";
        ascending(tp->right);
    }
}
void descending(NP tp){
    if(tp!=NULL){
        descending(tp->right);
        cout<<tp->data<<"("<<tp->copy<<"), ";
        descending(tp->left);
    }
}
int main(){
    int a[]={14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    int n=sizeof(a)/sizeof(int);
    NP root=NULL;
    for(int i=0;i<n;i++){
        add_node(&root,a[i]);
    }cout<<"ascending :";
    ascending(root);
    cout<<"\ndescending :";
    descending(root);
}
