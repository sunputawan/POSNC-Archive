#include <stdio.h>
#define size 5
int edge[5][5]={0,0,1,0,0,
                0,0,1,0,0,
                0,0,0,1,0,
                0,0,0,0,1,
                0,0,0,0,0};
int enable[5]={1,1,1,1,1};
int count=size;
void topological_sorting(int n){
    if(n<=count){
        int haveparent=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
                if(edge[j][i]==1){
                    haveparent=1;
                    count--;
                }
            if(!(haveparent)&&enable[i]==1){
                printf("c%d ", i+1);
                int havechild;
                for(int j=0;i<size;i++)
                    if(edge[i][j]==1){
                        havechild=1;
                    }
                if(!havechild)
                    printf("->");
                for(int j=0;j<size;j++)
                    edge[i][j]=0;
                enable[i]=0;
            }
        }
        topological_sorting(n+1);
    }
    else
        return;
}
int main(){
    topological_sorting(0);
}
