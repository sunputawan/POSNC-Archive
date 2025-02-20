#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int id;
};
typedef struct node* NP;
struct result{
    int ok;
    char contain[100001];   //char instead of int to reduce memory usage.
}ans[100];
NP make_node(void){
    NP new_node = (NP)malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->id = -1;

    return new_node;
}
int main(){
    int k,m,n;
    scanf("%d%d",&k,&m);
    struct node* root = make_node();

    for(int i=1;i<=k;i++){
        char tmp[m];
        scanf("%s", tmp);
        NP it=root;

        for(int j=0;j<m;j++){
            if(tmp[j]=='0'){
                if(it->left==NULL){
                    it->left = make_node();
                }
                it = it->left;
                continue;
            }
            if(tmp[j]=='1'){
                if(it->right==NULL){
                    it->right = make_node();
                }
                it = it->right;
            }
        }
        it->id = i;
    }
    scanf("%d", &n);

    for(int i=0;i<n;i++){   //initialization
        ans[i].ok = 1;
        for(int j=1;j<=k;j++)
            ans[i].contain[j] = 0;
    }

    for(int i=0;i<n;i++){
        int size;
        scanf("%d", &size);
        char ref[size];
        scanf("%s", ref);
        for(int j=0;j<=size-m;j++){
            NP it = root;
            for(int l=0;l<m;l++){
                if(ref[j+l]=='0'){
                    if(it->left==NULL){
                        break;
                    }
                    else
                        it = it->left;
                }
                if(ref[j+l]=='1'){
                    if(it->right==NULL){
                        break;
                    }
                    else
                        it = it->right;
                }
            }
            if(it->id!=-1){   //code detected
                ans[i].ok = 0;
                ans[i].contain[it->id] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i].ok)
            printf("OK");
        else{
            for(int j=1;j<=k;j++)
                if(ans[i].contain[j])
                    printf("%d ", j);
        }
        printf("\n");
    }
}
