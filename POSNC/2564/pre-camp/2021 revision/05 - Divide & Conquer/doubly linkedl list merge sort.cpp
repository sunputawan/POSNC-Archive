#include <iostream>
#define n 1000

using namespace std;
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef node* NP;
NP make_node(int x){
    NP new_node = new node;
    new_node->data=x;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}
void push(NP* head_ref,int x){
    NP new_node = make_node(x);
    if(*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    new_node->next = *head_ref;
    new_node->next->prev = new_node;
    *head_ref = new_node;
}
void printlist(NP head_ref){
    NP p=head_ref;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return;
}
void generate_list(NP* head_ref){
    for(int i=0;i<n;i++){
        push(head_ref,rand()%10000+1);
    }
}
NP merge(NP a,NP b){
    if(a==NULL) //base case
        return b;
    if(b==NULL)
        return a;
    if(a->data<=b->data){
        a->next = merge(a->next,b);
        a->next->prev =a;
        a->prev = NULL;
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
    if((*head_ref)->next==NULL) //base case (there is 1 node.)
        return;
    NP slow=*head_ref;
    NP fast=(*head_ref)->next;
    while(fast!=NULL){          //divide (fast runs as 2 times as slow.)
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
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
    cout<<"Is your list be sorted correctly? ... ";
    while(head->next!=NULL){
        if(head->data > head->next->data){
            cout<<"N\n";
            return;
        }
        head=head->next;
    }
    cout<<"Y\n";
}
int main(){
    NP head = NULL;
    generate_list(&head);
    cout<<"List ref : ";
    printlist(head);
    mergesort(&head);
    cout<<endl<<"Sorted list : ";
    printlist(head);
    check(head);
}
