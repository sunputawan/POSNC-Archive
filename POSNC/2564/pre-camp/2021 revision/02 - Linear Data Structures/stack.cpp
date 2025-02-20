#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define n 10

using namespace std;

struct my_stack{
    int top;
    int node[SIZE];
    my_stack(){
        top=-1;
    }
}st;
bool _is_empty(void){
    if (st.top==-1)
        return true;
    else
        return false;
}
void _empty(void){
    st.top=-1;
    return;
}
void push(int x){
    if(st.top==SIZE-1){
        cout<<"stack overflow!\n";
        return;
    }
    st.top++;
    st.node[st.top]=x;
    return;
}
int pop(void){
    if(_is_empty()){
        cout<<"stack underflow!\n";
    }
    else{
        st.top--;
        return st.node[st.top+1];
    }
}
void print_stack(void){
    cout<<"Your stack : ";
    for(int i=st.top;i>=0;i--)
        cout<<st.node[i]<<" ";
    cout<<endl;
}
int main(){
    srand(time(NULL));
    int *list_ref = new int[n];
    for(int i=0;i<n;i++){
        *(list_ref+i)= (rand()%100)+1;
    }
    cout<<"list_ref : ";
    for(int i=0;i<n;i++){
        cout<<list_ref[i]<<", ";
        push(list_ref[i]);
    }
    cout<<endl;
    print_stack();
    pop();
    print_stack();
    _empty();
    print_stack();
    pop();
}
