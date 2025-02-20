#include <iostream>

struct node{
    int data;
    struct node* next;
    node(){
        next=NULL;
    }
};
typedef struct node* NP;
using namespace std;
NP make_node(int x){
    NP new_node=(NP)malloc(sizeof(node));
    new_node->data=x;
    new_node->next=NULL;
    return new_node;
};
void print_list(NP head_ref){
    cout<<head_ref->data<<" ";
    head_ref=head_ref->next;
    while(head_ref->next!=NULL){
        cout<<head_ref->data<<" ";
        head_ref=head_ref->next;
    }
    cout<<head_ref->data;
}
void push_back(NP* head_ref,int x){
    NP p=*head_ref;
    NP new_node=make_node(x);
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new_node;
    return;
}
void push_front(NP* head_ref,int x){
    NP new_node=make_node(x);
    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    new_node->next=*head_ref;
    *head_ref=new_node;
    return;
}
int main(){
    NP head=NULL;
    push_back(&head,9);
    push_back(&head,12);
    push_back(&head,6);
    push_front(&head,2);
    push_back(&head,3);
    push_front(&head,0);
    print_list(head);
}

