#include <iostream>

using namespace std;
int data_list[] = {1,6,8,9,4,2,3,5};
int n =  sizeof(data_list)/sizeof(int);
struct node{
    int info;
    node* next;
};
typedef struct node* NP;
struct queue{
    NP front,rear;
    queue(){
        front=NULL;
        rear=NULL;
    }
}q;
NP make_node(int x){
    NP new_node = new node;
    new_node->info = x;
    new_node->next = NULL;
    return new_node;
}
void inject(int x){
    NP new_node = make_node(x);
    if(q.front==NULL){
        q.front = new_node;
        q.rear = new_node;
        return;
    }
    q.rear->next=new_node;
    q.rear = q.rear->next;
}
void push(int x){
    NP new_node = make_node(x);
    if(q.front == NULL){
        q.front = new_node;
        q.rear = new_node;
        return;
    }
    new_node->next = q.front;
    q.front = new_node;
}
void print_queue(void){
    cout<<"Your Queue: ";
    if(q.front==NULL)
        return;
    NP p= q.front;
    while(p!=NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
    cout<<endl;
}
void pop(void){
    if(q.front==NULL)
        return;
    int x = q.front->info;
    NP tmp = q.front;
    q.front = q.front->next;
    free(tmp);
    return;
}
void eject(void){
    if(q.front==NULL)
        return;
    NP tmp = q.front;
    while(tmp->next!=q.rear){
        tmp = tmp->next;
    }
    q.rear = tmp;
    free(tmp->next);
    q.rear->next=NULL;
}
int main(){
    for(int i=0;i<n;i++){
        inject(data_list[i]);
    }
    print_queue();
    pop();
    print_queue();
    eject();
    print_queue();
    push(99);
    print_queue();
}
