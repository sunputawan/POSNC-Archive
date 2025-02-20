#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack{
    int top;
    int item[SIZE];
};
typedef struct stack *SP;
SP new_stack(void){
    SP s = (SP)malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}
void push(SP s,int x){
    if(s->top==SIZE-1){
        return;
    }
    s->item[++s->top] = x;
}
void pop(SP s){
    if(s->top==-1){
        return;
    }
    s->top--;
}
int top(SP s){
    return s->item[s->top];
}
int size(SP s){
    return (s->top)+1;
}
int is_empty(SP s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void print_stack(SP s){
    for(int i=0;i<size(s);i++){
        printf("%d ", s->item[i]);
    }
}
int main(){
    int n;
    printf("Enter n : "); scanf("%d",&n);

    SP s1,s2,ans;
    s1 = new_stack();
    s2 = new_stack();
    ans = new_stack();

    printf("Input list : ");
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        push(s1,tmp);
    }
    int last=-1;
    while(size(ans)!=n){
        int t = top(s1); pop(s1);
        int count=0;
        int tmp = t;
        while(top(s1)>=tmp){
            tmp = top(s1);
            count++;
            pop(s1);
        }
        push(ans,last);
        while(count--){
            push(ans,last);
        }
        last = tmp;
    }
    printf("\nresult : ");
    while(!is_empty(ans)){
        printf("%d ", top(ans));
        pop(ans);
    }
    return 0;
}
