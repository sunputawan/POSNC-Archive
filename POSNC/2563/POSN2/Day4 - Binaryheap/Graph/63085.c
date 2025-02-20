#include <stdio.h>
#define size 8
struct node{
    char name[10];
    int distance;
    int enable;
    struct node* prev;
}district[8];
int edge[size][size]={0,5,37,10,4,15,26,30,
                    5,0,13,29,29,6,25,17,
                    37,13,0,26,22,30,2,18,
                    10,29,26,0,18,27,30,36,
                    4,29,22,18,0,29,17,20,
                    15,6,30,27,29,0,33,20,
                    26,25,2,30,17,33,0,23,
                    30,17,18,36,20,20,23,0};
void dijkstra(void){
        for(int i=0;i<size;i++){
        district[i].distance=100;
        district[i].enable=1;
        district[i].prev=NULL;
    }
    district[0].distance=0;
    for(int i=0;i<size;i++){
        if(district[i].enable==1){
            district[i].enable=0;
            for(int j=0;j<size;j++){
                struct node *p=district;
                if(i!=j&&district[j].distance>district[i].distance+edge[i][j]){
                    district[j].distance=district[i].distance+edge[i][j];
                    district[j].prev=district+i;
                }
            }
        }
    }
}
void path(struct node *p){
    if(p==NULL)
        return;
    path(p->prev);
    if(p->prev!=NULL)
        printf("->");
    printf("%s", p->name);
}
char namedis[8][10]={"ข่วงเปา","ดอยแก้ว","บ้านแปะ","บ้านหลวง","แม่สอย","ปิงโค้ง","สบเตี๊ยะ","เชียงดาว"};
int main(){
    for(int i=0;i<size;i++){
        for(int j=0;j<strlen(namedis[i]);j++)
            district[i].name[j]=namedis[i][j];
        //printf("%s\n", district[i].name);
    }
    dijkstra();
    for(int i=1;i<size;i++){
        struct node *p=district+i;
        printf("%s : %d (", district[i].name,district[i].distance,district[0].name);
        path(p);
        printf(")\n");
    }
}
