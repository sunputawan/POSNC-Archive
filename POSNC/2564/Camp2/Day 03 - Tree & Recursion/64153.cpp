#include <iostream>
#include <queue>

using namespace std;
vector<int> arr;
struct node{
    int val;
    int dup;
    struct node *l,*r;
    node(int x){
        l = NULL;
        r = NULL;
        val = x;
        dup = 1;
    }
};
typedef node *NP;
NP make_node(int x){
    NP new_node = new node(x);
    return new_node;
}
void push(NP *head_ref,int x){
    NP new_node = make_node(x);
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    NP p = *head_ref;
    while((x<p->val&&p->l!=NULL)||(x>p->val&&p->r!=NULL)){
        if(x<p->val)
            p = p->l;
        else
            p = p->r;
    }
    if(x==p->val){
        p->dup++;
        delete(new_node);
        return;
    }
    if(x<p->val)
        p->l = new_node;
    else
        p->r = new_node;

    return;
}
void inorder(NP p){
    if(p==NULL)
        return;
    inorder(p->l);
    cout<<p->val;
    if(p->dup>1){
        cout<<'('<<p->dup<<')';
    }
    cout<<' ';
    inorder(p->r);
}
void breadth_first_search(NP head){
    queue<node*> q;
    q.push(head);
    while(!q.empty()){
        NP p = q.front();
        q.pop();
        if(p->dup>1){
            cout<<p->val<<"\t"<<p->dup<<"\ttimes\n";
        }
        if(p->l!=NULL)
            q.push(p->l);
        if(p->r!=NULL)
            q.push(p->r);
    }
}
int max(NP head){
    NP p=head;
    while(p->r!=NULL)
        p=p->r;
    return p->val;
}
int min(NP head){
    NP p=head;
    while(p->l!=NULL)
        p=p->l;
    return p->val;
}
int count_leaf(NP p){
    if(p==NULL)
        return 0;
    if(p->l==NULL&&p->r==NULL)
        return 1;
    int total = count_leaf(p->l)+count_leaf(p->r);
    return total;
}
int count_height(NP p,int h){
    if(p==NULL)
        return h;
    int left = count_height(p->l,h+1);
    int right = count_height(p->r,h+1);
    return (left>right)?left:right;
}
int main(){
    int arr[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5};
    int n = sizeof(arr)/sizeof(int);
    NP head = NULL;
    cout<<"List ref : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        push(&head,arr[i]);
    }
    cout<<"\nDuplicate numbers are :\n";
    breadth_first_search(head);
    cout<<endl;
    cout<<"max : "<<max(head)<<endl;
    cout<<"min : "<<min(head)<<endl;
    cout<<"leaf : "<<count_leaf(head)<<endl;
    cout<<"height : "<<count_height(head,0)<<endl;
}
