#include <stdio.h>
#define SIZE 100
struct stack{
    int top;
    int item[100];
};
typedef struct stack *STP;
void push(struct stack *s,int x){
    if(s->top== SIZE-1){
        printf("Stack overflow");
        return;
    }
    else
        s->item[++(s->top)]=x;
}
int empty(struct stack *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int pop(struct stack *s){
    if(empty(s)){
        printf("%s", "stack underflow");
        return;
    }
    else
        return(s->item[s->top--]);
}
int main(){
    STP s1=(STP) malloc(sizeof(struct stack));
    STP s2=(STP) malloc(sizeof(struct stack));
    int n,a;
    s1->top=-1;
    s2->top=-1;
    scanf("%d", &n);
    int count[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        push(s1,a);
        count[i]=1;
    }
    for(int i=1;i<n;i++){
        s1->top=i-1;
        int j=1;
        while(s1->item[i]>s1->item[i-j]&&s1->top>=0){
            push(s2,pop(s1));
            count[i]++;
            j++;
        }
        while(!empty(s2)){
            push(s1,pop(s2));
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ", count[i]);
    return 0;
}
