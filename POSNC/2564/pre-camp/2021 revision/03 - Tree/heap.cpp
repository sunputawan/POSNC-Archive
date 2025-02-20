#include <iostream>
#include <vector>
#define SIZE 100
using namespace std;
int data_list[] = {65,21,24,26,31,32,68,19,16,13};
int n = sizeof(data_list)/sizeof(int);
int heap[SIZE]={};
int size=0;
void print_heap(void){
    cout<<"Your heap : ";
    for(auto i:heap){
        if(i==0)
        break;
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}
void insert_heap(int x){
    int hold=size;
    size++;
    int parent = (hold-1)/2;
    heap[hold]=x;
    while(heap[parent]>x){
        print_heap();
        heap[hold]=heap[parent];
        hold=parent;
        parent=(hold-1)/2;
        heap[hold]=x;
    }
    heap[hold]=x;
    print_heap();
    cout<<endl;
    return;
}
int main(){
    for(int i=0;i<n;i++){
        cout<<"n = "<<i<<endl;
        insert_heap(data_list[i]);
    }
    print_heap();
}
