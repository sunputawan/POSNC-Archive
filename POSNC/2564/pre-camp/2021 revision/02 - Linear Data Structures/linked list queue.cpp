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
void insert_node(int x){
    NP new_node = make_node(x);
    if(q.front==NULL){
        q.front = new_node;
        q.rear = new_node;
        return;
    }
    q.rear->next=new_node;
    q.rear = q.rear->next;
}
void print_queue(void){
    cout<<"Your Queue:";
    if(q.front==NULL)
        return;
    NP p= q.front;
    while(p!=NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
    cout<<endl;
}
int remove_node(void){
    if(q.front!=NULL){
        int x = q.front->info;
        NP tmp = q.front;
        q.front = q.front->next;
        free(tmp);
        return x;
    }
}
int main(){
    for(int i=0;i<n;i++){
        insert_node(data_list[i]);
    }
    print_queue();
    remove_node();
    remove_node();
    print_queue();

}
