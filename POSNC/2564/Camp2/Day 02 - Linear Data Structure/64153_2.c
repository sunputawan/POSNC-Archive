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
    printf("\n");
}
int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}
int main(){
    int n;
    printf("Enter n : "); scanf("%d",&n);
    int arr[n];
    printf("Input list : ");
    int max = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    SP s = new_stack();
    int ans=0;
    for(int i=0;i<n;i++){
        while(!is_empty(s)&&arr[top(s)]<arr[i]){
            //print_stack(s);
            int htop = arr[top(s)]; pop(s);
            if(is_empty(s))
                break;
            int distance = i-top(s)-1;
            int hmin = min(arr[top(s)],arr[i])-htop;
            ans += distance*hmin;
        }
        push(s,i);
    }
    printf("Total : %d", ans);
}
