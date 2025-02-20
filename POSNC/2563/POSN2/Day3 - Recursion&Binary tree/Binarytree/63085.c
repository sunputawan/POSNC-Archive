#include <stdio.h>
#define size 15
int height=0,leaf=0;
int dup=0;
struct tree{
    int info;
    struct tree *left;
    struct tree *right;
    int count;
};
struct tree *root;
struct tree* maketree(int x){
    struct tree *tmp=(struct tree*) malloc(sizeof(struct tree));
    tmp->info=x;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->count=0;
    return tmp;
}
int findmin(struct tree *p){
    while(p->left!=NULL)
        p=p->left;
    return p->info;
}
int findmax(struct tree *p){
    while(p->right!=NULL)
        p=p->right;
    return p->info;
}
void setleft(struct tree *p,int x){
    if(p==NULL){
        printf("can't set left child to tree\n");
        return;
    }
    if(p->left!=NULL){
        printf("Tree has already have left child\n");
    }
    else
        p->left = maketree(x);
}
void setright(struct tree *p,int x){
    if(p==NULL){
        printf("can't set right child to tree\n");
        return;
    }
    else{
        if(p->right!=NULL)
            printf("Tree has already have right child\n");
        else
            p->right = maketree(x);
    }
}
void inorder(struct tree *p){
    if(p != NULL){
        inorder(p->left);
        printf("%d ", p->info);
        inorder(p->right);
    }
}
void inserttree(int input){
    if(root == NULL){
        root = maketree(input);
        return;
    }
    struct tree *tmp=root;
    while((tmp->left!=NULL&&input<tmp->info)||(tmp->right!=NULL&&input>=tmp->info)){
        if(input<tmp->info)
            tmp=tmp->left;
        else
            tmp=tmp->right;
    }
    if(input<tmp->info)
        setleft(tmp,input);
    else
        setright(tmp,input);
}
void countleaf(struct tree *p){
    if(p==NULL)
        return;
    if(p->left==NULL&&p->right==NULL)
        leaf++;
    else{
        countleaf(p->left);
        countleaf(p->right);
    }
}
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int findheight(struct tree *p){
    if(p==NULL)
        return 0;
    return max(findheight(p->left),findheight(p->right))+1;
}
int countDupes(struct tree *p, int val){
    if(p==NULL){
        return;
    }
    if(p->info==val){
        p->count++;
        return;
    }
    else{
        countDupes(p->left,val);
        countDupes(p->right,val);
    }
}
void displaydup(struct tree *p,int a[]){
    if(p==root){
        for(int i=0;i<size;i++){
            countDupes(root,a[i]);
        }
    }
    if(p==NULL)
        return;
    if(p->count>1)
        printf("\n%d : %d times", p->info,p->count);
    displaydup(p->left,a);
    displaydup(p->right,a);
}
int main(){
    int input[]={14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};
    for(int i=0;i<size;i++){
        inserttree(input[i]);
    }
    inorder(root);
    printf("\n");
    displaydup(root,input);
    countleaf(root);
    printf("\n");
    printf("min : %d\nmax : %d\n", findmin(root),findmax(root));
    printf("leaf : %d\n", leaf);
    printf("height : %d", findheight(root));

}
