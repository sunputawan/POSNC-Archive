#include <iostream>
#define n 50000

using namespace std;
struct node{
    int data;
    struct node* prev;
    struct node* next;
    node(){
        prev=NULL;
        next=NULL;
    }
};
typedef node* NP;
NP make_node(int x){
    NP new_node = new node;
    new_node->data=x;
    return new_node;
}
void push(NP *head_ref,int x){
    NP new_node = make_node(x);
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
    *head_ref = new_node;

    return;
}
void generate_list(NP *head){
    for(int i=0;i<n;i++){
        push(head,rand()%10000+1);
    }
}
void printlist(NP head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl<<endl;
}
NP merge(NP a,NP b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data<=b->data){
        a->next = merge(a->next,b);
        a->next->prev = a;
        a->prev=NULL;
        return a;
    }
    else{
        b->next = merge(a,b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}
void mergesort(NP *head_ref){
    if((*head_ref)->next==NULL)
        return;
    NP slow = *head_ref;
    NP fast = slow->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    NP a=*head_ref;
    NP b=slow->next;
    slow->next=NULL;

    mergesort(&a);
    mergesort(&b);

    *head_ref = merge(a,b);
}
void check(NP head){
    cout<<"Is your list be sorted correctly : ";
    while(head->next!=NULL){
        if(head->data>head->next->data){
            cout<<"N\n";
            return;
        }
        head=head->next;
    }
    cout<<"Y\n";
}
int main(){
    NP head=NULL;
    generate_list(&head);
    cout<<"List ref : ";
    printlist(head);
    mergesort(&head);
    cout<<"Sorted list : ";
    printlist(head);
    check(head);
}
