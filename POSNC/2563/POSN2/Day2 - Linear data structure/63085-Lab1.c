#include <stdio.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node *STP;
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
int countpairs(STP head1,STP head2,int x){
    STP p2;
    p2=head2;
    int count=0;
    while(head1!=NULL){
        while(head2!=NULL){
            if(head1->info==x-head2->info){
                    count++;
                    break;
            }
            head2=head2->next;
        }
        head2=p2;
        head1=head1->next;
    }
    return count;
}
int main(){
    STP l1=NULL,l2=NULL;
    int s1,s2,x,a;
    printf("Enter list1 and list2 size respectively :");
    scanf("%d%d", &s1,&s2);
    printf("\n");
    for(int i=0;i<s1;i++){
        printf("L1 node%d : ", i+1);
        scanf("%d", &a);
        append(&l1,a);
    }
    printf("\n");
    for(int i=0;i<s2;i++){
        printf("L2 node%d : ", i+1);
        scanf("%d", &a);
        append(&l2,a);
    }
    printf("\n");
    printf("X = ");
    scanf("%d", &x);
    printf("count = %d", countpairs(l1,l2,x));
}
