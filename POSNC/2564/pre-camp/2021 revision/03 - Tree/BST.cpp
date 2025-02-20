#include <iostream>

using namespace std;
//int data_list[] = {10,10,10,10,10,10,7,7,7,7,7,7};
int data_list[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
int n = sizeof(data_list)/sizeof(int);
struct node{
    int data;
    int duplicates;
    node* l;
    node* r;
    node(){
        l=NULL;
        r=NULL;
        duplicates=0;
    }
};
typedef node* NP;
NP make_node(int x){
    NP new_node = new node;
    new_node->data = x;
    return new_node;
}
void insert_node(NP *root_ref,int x){
    NP new_node = make_node(x);
    if(*root_ref==NULL){
        *root_ref=new_node;
        return;
    }
    NP p=*root_ref;
    while((x<p->data&&p->l!=NULL)||(x>p->data&&p->r!=NULL)){
        if(x<p->data)
            p=p->l;
        else if(x>p->data)
            p=p->r;
        else{
            p->duplicates++;
            return;
        }
    }
    if(x<p->data)
        p->l=new_node;
    else if(x>p->data)
        p->r=new_node;
    else
        p->duplicates++;
}
void print_node(NP np){
    cout<<np->data;
    if(np->duplicates!=0)
        cout<<'('<<np->duplicates+1<<')';
    cout<<' ';
}
void preorder(NP root){
    if(root==NULL)
        return;
    print_node(root);
    preorder(root->l);
    preorder(root->r);
}
void inorder(NP root){
    if(root==NULL)
        return;
    inorder(root->l);
    print_node(root);
    inorder(root->r);
}
void postorder(NP root){
    if(root==NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    print_node(root);
}
bool search_node(NP root,int x){
    while(root!=NULL){
        if(x<root->data)
            root=root->l;
        else if(x>root->data)
            root=root->r;
        else
            return true;
    }
    return false;
}
int smallest(NP root){
    while(root->l!=NULL){
        root=root->l;
    }
    return root->data;
}
int largest(NP root){
    while(root->r!=NULL){
        root=root->r;
    }
    return root->data;
}
int main(){
    NP root=NULL;
    for(int i=0;i<n;i++){
        insert_node(&root,data_list[i]);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl<<endl;
    if(search_node(root,5))
        cout<<"5 is in BST"<<endl;
    else
        cout<<"5 isn't in BST"<<endl;
    if(search_node(root,0))
        cout<<"0 is in BST"<<endl;
    else
        cout<<"0 isn't in BST"<<endl;
    cout<<endl<<"The samllest one is "<<smallest(root)<<endl;
    cout<<"The biggest one is "<<largest(root)<<endl;
}
