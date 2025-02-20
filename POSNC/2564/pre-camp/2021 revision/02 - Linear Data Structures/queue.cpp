#include <iostream>
#define MAXQUEUE 8

using namespace std;
int data_list[] = {1,6,8,9,4,2,3,5};
int n =  sizeof(data_list)/sizeof(int);
struct queue{
    int item[MAXQUEUE];
    int front;
    int rear;
    int size;
    queue(){
        front=-1;
        rear=-1;
        size=0;
    }
}q;
void enqueue(int x){
    if(q.size==MAXQUEUE){
        return;
    }
    q.rear++;
    if(q.rear==MAXQUEUE){
        q.rear=0;
    }
    q.item[q.rear] = x;
    if(q.size==0){
        q.front=0;
    }
    q.size++;
}
int dequeue(void){
    if(q.size!=0){
        int x=q.front;
        q.front++;
        if(q.front==MAXQUEUE)
            q.front=0;
        if(q.size==1){
            q.rear=-1;
            q.front=q.rear;
        }
        q.size--;
        return x;
    }
}
void print_queue(void){
    int x=q.front;
    int count=0;
    cout<<"Your Queue : ";
    while(count!=q.size){
        if(x==MAXQUEUE){
            x=0;
        }
        cout<<q.item[x]<<" ";
        x++;
        count++;
    }
    cout<<endl;
}
int main(){
    cout<<"List Ref : ";
    for(int i=0;i<n;i++){
        enqueue(data_list[i]);
        cout<<data_list[i]<<" ";
    }
    cout<<endl<<endl;
    print_queue();
    cout<<q.front<<" "<<q.rear<<endl<<endl;
    dequeue();
    print_queue();
    cout<<q.front<<" "<<q.rear<<endl<<endl;
    dequeue();
    print_queue();
    cout<<q.front<<" "<<q.rear<<endl<<endl;
    enqueue(99);
    print_queue();
    cout<<q.front<<" "<<q.rear<<endl<<endl;
    enqueue(0);
    print_queue();
    cout<<q.front<<" "<<q.rear<<" "<<endl<<endl;
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    print_queue();
    enqueue(3);
    enqueue(17);
    enqueue(61);
    dequeue();
    dequeue();
    dequeue();
    print_queue();
}
