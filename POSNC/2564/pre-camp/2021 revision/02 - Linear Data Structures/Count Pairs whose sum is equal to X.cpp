#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
int list1[]= {7,5,1,6};
int list2[]= {3,2,5,8};
int x=8;
struct node{
    int data;
    node* next;
    node(){
        next=NULL;
    }
};
typedef node* NP;
void push(NP *head_ref,int x){
    NP new_node = new node;
    new_node->data = x;

    //This pushing algorithm will push the data in reverse order but take no time to find its position.
    new_node->next=*head_ref;
    *head_ref=new_node;
}
int countpairs(NP head1, NP head2){
    int count=0;
    unordered_set<int> us;
    while(head1!=NULL){
        us.insert(head1->data);
        head1=head1->next;
    }
    while(head2!=NULL){
        int target = x-head2->data;
        if(us.find(target)!=us.end())
            count++;
        head2=head2->next;
    }
    return count;
}
int main(){
    NP head1 = NULL;
    NP head2 = NULL;

    for(int i=0;i<sizeof(list1)/sizeof(int);i++)
        push(&head1,list1[i]);
    for(int i=0;i<sizeof(list2)/sizeof(int);i++)
        push(&head2,list2[i]);
    cout<<"count = "<<countpairs(head1,head2);
}
