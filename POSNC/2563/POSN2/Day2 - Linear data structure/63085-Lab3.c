#include <stdio.h>
struct deque{
    struct deque* left;
    struct deque* right;
    int data;
};
typedef struct deque* DP;
DP getnode(void){
    DP new_node=(DP) malloc(sizeof(struct deque));
    return new_node;
}
void push(DP *head_ref,int x){
    DP new_node=getnode();
    new_node->left=NULL;
    new_node->data=x;
    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->right=NULL;
        new_node->left=NULL;
        return;
    }
    new_node->right=*head_ref;
    new_node->right->left=new_node;
    *head_ref=new_node;
}
int pop(DP *head_ref){
    DP p;
    p=*head_ref;
    *head_ref=p->right;
    p->right->left=NULL;
    p->right=NULL;
    int a=p->data;
    free(p);
    return a;
}
void inject(DP *head_ref,int x){
    DP new_node=getnode();
    new_node->right=NULL;
    new_node->data=x;
    DP p=*head_ref;
    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->left=NULL;
        return;
    }
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=new_node;
    new_node->left=p;
}
int eject(DP head_ref){
    if(head_ref==NULL){
        printf("Deque is empty.");
        return;
    }
    DP p=head_ref;
    while(p->right!=NULL){
        p=p->right;
    }
    int x=p->data;
    p->left->right=NULL;
    free(p);
    return x;
}
void empty(DP head_ref){
    if(head_ref==NULL)
        return 1;
    else
        return 0;
}
void printdeq(DP head_ref){
    if(head_ref==NULL){
        printf("Deque is empty.");
        return;
    }
    while(head_ref->right!=NULL){
        printf("%d ", head_ref->data);
        head_ref=head_ref->right;
    }
    printf("%d\n", head_ref->data);
}
int main(){
    DP head = NULL;
    int a;
    for(int i=0;i<5;i++){
        scanf("%d", &a);
        inject(&head,a);
    }
    printdeq(head);
    printf("%d\n", pop(&head));
    printdeq(head);
    printf("%d\n",eject(head));
    printdeq(head);
    push(&head,77);
    printdeq(head);

}
