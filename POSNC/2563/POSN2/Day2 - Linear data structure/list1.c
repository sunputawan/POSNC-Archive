#include <stdio.h>
struct node{
    int info;
    struct node *next;
};
void append(struct node** head_ref,int new_data){
   struct node* new_node=(struct node*) malloc(sizeof(struct node));
   struct node* last = *head_ref;
   new_node->info=new_data;
   new_node->next=NULL;
   if(*head_ref==NULL){
        *head_ref=new_node;
        return;
   }
   while(last->next!=NULL)
        last=last->next;
    last->next=new_node;
    return;
}
void push(struct node** head_ref,int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->info=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void printlist(struct node* head_ref){
    if(head_ref==NULL){
        printf("Link is empty!");
        return;
    }
    while(head_ref->next!=NULL){
        printf("%d ", head_ref->info);
        head_ref=head_ref->next;
    }
    printf("%d\n", head_ref->info);
    return;
}
void insertAfter(struct node *ref_head,int ref_data, int new_data){
    while(ref_head->info!=ref_data){
        ref_head=ref_head->next;
        if(ref_head->next==NULL&&ref_head->info!=ref_data){
            printf("\'%d\' not detected in this list.", ref_data);
            return;
        }
    }
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    new_node->info=new_data;
    new_node->next=ref_head->next;
    ref_head->next=new_node;
}
int main(){
    int n,a;
    struct node* head = NULL;
    printf("Enter number of node : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        append(&head,a);
    }
    printlist(head);
    push(&head,7);
    printlist(head);
    insertAfter(head,7,12);
    printlist(head);
    return 0;
}
