#include <iostream>
#include <stdlib.h>

using namespace std;

int n=10;
int deleting_value=26500;
int deleting_index=9;
struct node{
    int data;
    node* next;
};
typedef node* NP;
void define_list(int *list1){
    for(int i=0;i<n;i++){
        *(list1+i)=rand();
    }
}
NP make_node(int new_data){
    NP new_node = new node;
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int list_size(NP head_ref){
    int j=1;
    while(head_ref->next!=NULL){
        j++;
        head_ref=head_ref->next;
    }
    return j;
}
void pushback(NP* head_ref,int new_data){
    NP new_node = make_node(new_data);
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    NP node_pointer = *head_ref;
    while(node_pointer->next!=NULL){
        node_pointer=node_pointer->next;
    }
    node_pointer->next=new_node;
}
void pushfront(NP* head_ref,int new_data){
    NP new_node = make_node(new_data);
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    new_node->next = *head_ref;
    *head_ref = new_node;

}
void print_list(NP head_ref){
    if(head_ref==NULL){
        cout<<"Your list is empty!"<<endl;
        return;
    }
    cout<<"Your List ( "<<list_size(head_ref)<<" element(s)) : ";
    while(head_ref!=NULL){
        cout<<head_ref->data<<", ";
        head_ref=head_ref->next;
    }
    cout<<endl;
    return;
}
void del_value(NP* head_ref,int value){
    NP node_pointer = *head_ref;
    if (node_pointer->data == value){       //check whether it is first element
        *head_ref=node_pointer->next;
        node_pointer->next=NULL;
        free(node_pointer);
        return;
    }
    while(node_pointer->next->data!=value&&node_pointer->next->next!=NULL){
        node_pointer=node_pointer->next;
    }
    if(node_pointer->next->data!=value&&node_pointer->next->next==NULL){ //check whether the last element is value we are searching?
        return;
    }
    NP node_tmp=node_pointer->next;
    node_pointer->next=node_pointer->next->next;
    node_tmp->next=NULL;
    free(node_tmp);
}
void del_index(NP* head_ref,int index){
    if(index>=list_size(*head_ref)){
        cout<<"Error ,Index out of range!"<<endl;
        return;
    }
    NP node_pointer = *head_ref;
    if(index==0){
        *head_ref=node_pointer->next;
        node_pointer->next==NULL;
        free(node_pointer);
        return;
    }
    int j=1;
    while(j!=index){
        node_pointer=node_pointer->next;
        j++;
    }
    NP node_tmp=node_pointer->next;
    node_pointer->next=node_pointer->next->next;
    node_tmp->next==NULL;
    free(node_tmp);
}
int find_info(NP head_ref,int key){
    int index=0;
    while(head_ref->data!=key&&head_ref->next!=NULL){
        head_ref=head_ref->next;
        index++;
    }
    if(head_ref->data!=key){
        cout<<"'"<<key<<"' not found in your list! "<<endl;
        return -1;
    }
    else
        index++;
    return index;
}
void insert_data(NP* head_ref,int index,int data){
    if(index<=0){
        pushfront(head_ref,data);
        return;
    }
    if(index>=list_size(*head_ref)-1){
        pushback(head_ref,data);
        return;
    }
    NP node_pointer = *head_ref;
    int j=1;
    while(j!=index){
        node_pointer=node_pointer->next;
        j++;
    }
    NP new_node = make_node(data);
    new_node->next = node_pointer->next;
    node_pointer->next = new_node;
    return;
}
void empty_list(NP* head_ref){
    NP node_pointer = *head_ref;
    NP node_tmp = *head_ref;
    *head_ref=NULL;
    while(node_pointer->next!=NULL){
        node_pointer=node_pointer->next;
        node_tmp->next=NULL;
        free(node_tmp);
        node_tmp=node_pointer;
    }
    free(node_pointer);
}
int main(){
    int* my_list = new int[n];
    define_list(my_list);
    NP head_ref=NULL; //initialization
    cout<<"ref_list >>> ";
    for(int i=0;i<n;i++){
        cout<<my_list[i]<<" ";
        pushback(&head_ref,my_list[i]);
    }
    cout<<endl;
    print_list(head_ref);
    pushback(&head_ref,3);
    print_list(head_ref);
    del_value(&head_ref,deleting_value);
    print_list(head_ref);
    del_index(&head_ref,deleting_index);
    print_list(head_ref);
    cout<<find_info(head_ref,41)<<endl;
    cout<<find_info(head_ref,40)<<endl;
    empty_list(&head_ref);
    print_list(head_ref);
    cout<<endl<<endl<<endl<<"Assign value again"<<endl<<endl;
    int* new_list = new int[n];
    define_list(new_list);
    cout<<"ref_list >>> ";
    for(int i=0;i<n;i++){
        cout<<new_list[i]<<" ";
        pushfront(&head_ref,new_list[i]);
    }
    cout<<endl;
    print_list(head_ref);
    cout<<endl;
    insert_data(&head_ref,0,99);
    print_list(head_ref);
    insert_data(&head_ref,-4599,72);
    print_list(head_ref);
    insert_data(&head_ref,list_size(head_ref)-1,17);
    print_list(head_ref);
    insert_data(&head_ref,651698,123456);
    print_list(head_ref);
    insert_data(&head_ref,5,10101010);
    print_list(head_ref);
}
