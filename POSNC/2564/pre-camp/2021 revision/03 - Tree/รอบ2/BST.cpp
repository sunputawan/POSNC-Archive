#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define n 10

using namespace std;
vector<int> arr;
struct node{
    int val;
    int dup;
    node *left;
    node *right;
    node(int x){
        val = x;
        left=NULL;
        right=NULL;
        dup=1;
    }
};
typedef node *NP;
void generate_input(void){
    cout<<"List ref : ";
    for(int i=0;i<n;i++){
        arr.push_back(rand()%100+1);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void add_node(NP* root_ref,int x){
    if(*root_ref==NULL){
        *root_ref = new node(x);
        return;
    }
    NP p = *root_ref;
    while((x<p->val&&p->left!=NULL)||(x>=p->val&&p->right!=NULL)){
        if(p->val==x){
            p->dup++;
            return;
        }
        if(x<p->val)
            p=p->left;
        else
            p=p->right;
    }
    if(x<p->val)
        p->left = new node(x);
    else
        p->right = new node(x);
    return;
}
void inorder(NP p){
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<p->val;
    if(p->dup>1)
        cout<<"("<<p->dup<<")";
    cout<<" ";
    inorder(p->right);
}
void BFS(NP head_ref){
    cout<<"Breadth First Search : ";
    NP p = head_ref;
    queue<node*> q;
    q.push(head_ref);
    while(!q.empty()){
        NP tmp =  q.front();
        cout<<tmp->val;
        if(tmp->dup>1)
            cout<<"("<<tmp->dup<<")";
        cout<<" ";
        q.pop();
        if(tmp->left!=NULL) q.push(tmp->left);
        if(tmp->right!=NULL) q.push(tmp->right);
    }
}
void DFS(NP head_ref){
    cout<<"Depth First Search : ";
    NP p = head_ref;
    stack<node*> s;
    s.push(head_ref);
    while(!s.empty()){
        NP tmp =  s.top();
        cout<<tmp->val;
        if(tmp->dup>1)
            cout<<"("<<tmp->dup<<")";
        cout<<" ";
        s.pop();
        if(tmp->right!=NULL) s.push(tmp->right);
        if(tmp->left!=NULL) s.push(tmp->left);
    }
}
void delete_node(NP* head_ref,int target){
    if(*head_ref==NULL)
        return;
    NP p = *head_ref;
    NP prev = *head_ref;
    bool first_time = true;
    while(p->val!=target){
        if(!first_time)
            prev=p;
        if(first_time)
            first_time = false;
        if(target<p->val)
            p=p->left;
        else
            p=p->right;
        if(p==NULL)
            break;
    }
    if(p==NULL)
        return;     //not found
    if(p->dup>1){
        p->dup--;
        return;
    }
    if(p->left==NULL&&p->right==NULL){
        free(p);
        if(target<prev->val)
            prev->left=NULL;
        if(target>prev->val)
            prev->right=NULL;
        return;
    }
    if(p->left==NULL){
        if(target<prev->val)
            prev->left = p->right;
        if(target>prev->val)
            prev->right = p->right;
        free(p);
        return;
    }
    if(p->right==NULL){
        if(target<prev->val)
            prev->left = p->left;
        if(target>prev->val)
            prev->right = p->left;
        free(p);
        return;
    }
    NP max_left = p;
    NP prev_max_left = p;
    prev_max_left = prev_max_left->left;
    while(prev_max_left->right!=NULL){
        prev_max_left = max_left;
        max_left = max_left->right;
    }
    prev_max_left->right = NULL;
    max_left->left = p->left;
    max_left->right = p->right;
    if(target<prev->val)
        prev->left = max_left;
    if(target>prev->val)
        prev->right = max_left;
    free(p);
    NP head = *head_ref;
    if(head->val==target){
        *head_ref = max_left;
    }
    return;

}
int main(){
    NP head = NULL;
    generate_input();
    for(auto num:arr){
        add_node(&head,num);
    }
    cout<<"Inorder : ";
    inorder(head);
    cout<<endl;
    BFS(head);
    cout<<endl;
    DFS(head);
    cout<<endl;
    delete_node(&head,68);
    cout<<"Inorder : ";
    inorder(head);
}
